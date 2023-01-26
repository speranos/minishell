/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:42:04 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/26 00:46:58 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_next_qoutes(t_token *link, char c)
{
	while (link->str[link->i])
	{
		if (link->str[link->i] == c)
		{
			link->i++;
			break ;
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
		if (link->str[link->i] == 39 || link->str[link->i] == 34)
		{
			c = link->str[link->i++];
			ft_next_qoutes(link, c);
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
		if (link->str[link->i] == 39 || link->str[link->i] == 34)
		{
			c = link->str[link->i++];
			ft_quote_to_skip(link, c, str);
		}
		else
			str[link->len++] = link->str[link->i++];
	}
	str[link->len] = '\0';
	free(link->str);
	link->str = str;
}

void	ft_remove_quotes(t_token *link)
{
	while (link)
	{
		if (link->e_type == 0 || link->e_type >= 2)
			ft_skip(link);
		link = link->next;
	}
}

void	ft_quote_to_skip(t_token *link, char c, char *str)
{
	while (link->str[link->i])
	{
		if (link->str[link->i] == c)
		{
			link->i++;
			break ;
		}
		str[link->len++] = link->str[link->i++];
	}
}
