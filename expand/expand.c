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
	link->index = 0;
	link->i = 0;
	while (link->str[link->i])
	{
		if(link->str[link->i] == 36)
			ft_dollar(link);
		else if(link->str[link->i] == 34)
			link->index++;
		else if(link->str[link->i] == 39 && (link->index == 0 || link->index % 2 == 0))
			ft_single(link);
		link->i++;
	}
}

void	ft_single(t_token *link)
{
	char	c;

	c = link->str[link->i];
	//printf("c ============= %c\n", c);
	link->i++;
	while (link->str[link->i] && link->str[link->i] != c)
	{
		if(link->str[link->i] == 34)
			link->index++;
		link->i++;
	}
	link->i--;
}

void	ft_dollar(t_token *link)
{
	int		tmp;
	char	c;

	tmp = 0;
	c = link->str[link->i + 1];
	if(ft_alpha(link) == 1)
		return;
	tmp = link->i++;
	while (link->str[link->i] && ft_alphanum(c) != 1)
			c = link->str[++link->i];
	link->len = link->i - tmp;
	ft_update_ex(link, tmp);
	link->i = -1;
}

void	ft_update_ex(t_token *link, int tmp)
{
	char	*str;
	char	*get_str;
	int		i;
	int		index;

	index = tmp;
	i = 0;
	str = malloc(sizeof(char) * link->len);
	tmp++;
	while(tmp < link->i)
	{
		str[i++] = link->str[tmp++];
	}
	str[i] = '\0';
	get_str = getenv(str);
	ft_link_update(link, get_str, index, i);
	free(str);
}

void	ft_link_update(t_token *link, char *str, int index, int def)
{
	int	link_len;
	int	str_len;
	int	len;
	char	*fin_str;

	link_len = ft_len(link->str);
	str_len = ft_len(str);
	len = (link_len - (def + 1)) + str_len;
	fin_str = malloc(sizeof(char) * len + 1);
	ft_to_fin_str(link, str, fin_str, index, def);
	fin_str[link->len] = '\0';
	free(link->str);
	link->str = fin_str;
	link->index = 0;
}

void	ft_to_fin_str(t_token *link, char *str, char *fin_str, int index, int def)
{
	int	str_len;
	int	link_len;

	str_len = 0;
	link_len = 0;
	link->len = 0;
	while(link->str[link_len])
	{
		if(link_len == index)
		{
			if(str != NULL)
			{	
				while(str[str_len] != '\0')
					fin_str[link->len++] = str[str_len++];
			}
			link_len += def + 1;
		}
		else
			fin_str[link->len++] = link->str[link_len++];
	}
}

int	ft_len(char *str)
{
	int	i;

	i = 0;
	if(str == NULL)
		return(0);
	while (str[i])
		i++;
	return(i);
}

int	ft_alphanum(char c)
{
	if(c >= 48 && c <= 57)
		return(0);
	else if(c >= 65 && c <= 90)
		return(0);
	else if (c >= 97 && c <= 122)
		return(0);
	return(1);
}

int	ft_alpha(t_token *link)
{
	char	c;

	c = link->str[link->i + 1];
	if(c >= 48 && c <= 57)
		ft_rm_num(link);
	else if(c == 34 || c == 39)
		ft_rm_dollar(link);
	else if(c == '?')
		ft_quest_mark(link);
	else if(c >= 65 && c <= 90)
		return(0);
	else if (c >= 97 && c <= 122)
		return(0);
	else 
		return(1);
	return(1);
}

void	ft_rm_num(t_token *link)
{
	int	tmp;

	tmp = link->i;
	link->i += 2;
	link->len = 3;
	ft_update_ex(link, tmp);
}

void	ft_rm_dollar(t_token *link)
{
	int	tmp;

	tmp = link->i++;
	link->len = 2;
	ft_update_ex(link, tmp);
}

void	ft_quest_mark(t_token *link)
{
	char	*str;
	int		index;
	int		len;

	str = itoa(exit_error);
	index = link->i;
	len = link->i + 1;
	ft_link_update(link, str, index, len);
	free(str);
}

char	*itoa(int num)
{
	int	len;
	char *str;

	len = ft_num_len(num);
	str = malloc(sizeof(char) * len + 1);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = (num % 10) + 48;
		num /= 10;
	}
	return(str);
}

int	ft_num_len(int num)
{
	int	i;

	i = 0;
	if(num == 0)
		return(1);
	while(num > 0)
	{
		num /= 10;
		i++;
	}
	return(i);
}