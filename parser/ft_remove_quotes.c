#include "../minishell.h"

void	ft_next_qoutes(t_token *link, char c)
{
	while(link->str[link->i])
	{
		if(link->str[link->i] == c)
		{
			link->i++;
			break;
		}
		link->i++;
		link->len++;
	}
}

void	ft_len_quotes(t_token *link)
{
	char	c;

	link->len = 0;
	link->i = 0;
	while (link->str[link->i])
	{
		if(link->str[link->i] == 39 || link->str[link->i] == 34)
		{
			c = link->str[link->i++];
			ft_next_qoutes(link,c);
		}
		else
		{
			link->i++;
			link->len++;
		}
	}
}

void	ft_skip(t_token *link)
{
	char	*str;
	char	c;

	ft_len_quotes(link);
	str = malloc(sizeof(char) * link->len + 1);
	link->i = 0;
	link->len = 0;
	while (link->str[link->i])
	{
		if(link->str[link->i] == 39 || link->str[link->i] == 34)
		{
			c = link->str[link->i];
			link->i++;
			while(link->str[link->i])
			{
				if(link->str[link->i] == c)
				{
					link->i++;
					break;
				}
				str[link->len++] = link->str[link->i++];
			}
		}
		else
			str[link->len++] = link->str[link->i++];
	}
	str[link->len] = '\0';
	link->str = str;
}

void	ft_remove_quotes(t_token **link)
{
	t_token *head;

	head = *link;
	while (*link)
	{
		if((*link)->type == 0 || (*link)->type >= 2)
			ft_skip(*link);
		*link = (*link)->next;
	}
	*link = head;
}