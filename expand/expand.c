#include "../minishell.h"

void	ft_expand(t_token *link)
{
	while (link)
	{
		if(link->type == 0 || link->type >= 2)
			ft_check(link);
		link = link->next;
	}
}

void	ft_check(t_token *link)
{
	// printf("hoooooodhod\n");
	link->i = 0;
	while (link->str[link->i])
	{
		if(link->str[link->i] == 36)
			ft_dollar(link);
		else if(link->str[link->i] == 39)
			ft_single(link);
		link->i++;
	}
	
}

void	ft_single(t_token *link)
{
	char	c;

	c = link->str[link->i];
	link->i++;
	while (link->str[link->i] && link->str[link->i] != c)
		{
			printf("c =>>>>>>>>>>> %c\n", link->str[link->i]);
			link->i++;
		}
	printf("sefger\n");
	
}

void	ft_dollar(t_token *link)
{
	int		tmp;
	char	c;
	char	*str;

	tmp = link->i++;
	c = link->str[link->i];
	if(ft_alpnum(c) == 1)
		return;
	while (link->str[link->i] && ft_alpnum(c) != 1)
	{
		link->i++;
	}
	
}

int	ft_alpnum(char c)
{
	if(c >= 48 && c <= 57)
		return(0);
	else if(c >= 65 && c <= 90)
		return(0);
	else if (c >= 97 && c <= 122)
		return(0);
	return(1);
}