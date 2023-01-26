/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:54:46 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/26 10:54:48 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_expand(t_token *link, t_envir *envir)
{
	while (link)
	{
		if (link->e_type == 0 || link->e_type >= 2)
			ft_check(link, envir);
		link = link->next;
	}
}

void	ft_check(t_token *link, t_envir *envir)
{
	link->index = 0;
	link->i = 0;
	while (link->str[link->i])
	{
		if (link->str[link->i] == 36)
			ft_dollar(link, envir);
		else if (link->str[link->i] == 34)
			link->index++;
		else if (link->str[link->i] == 39 && (link->index == 0
				|| link->index % 2 == 0))
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
		if (link->str[link->i] == 34)
			link->index++;
		link->i++;
	}
	if (link->str[link->i] == '\0')
		link->i--;
}

void	ft_dollar(t_token *link, t_envir *envir)
{
	int		tmp;
	char	c;

	tmp = 0;
	c = link->str[link->i + 1];
	if (ft_alpha(link, envir) == 1)
		return ;
	tmp = link->i++;
	while (link->str[link->i] && ft_alphanum(c) != 1)
			c = link->str[++link->i];
	link->len = link->i - tmp;
	ft_update_ex(link, tmp, envir);
	link->i = -1;
}
