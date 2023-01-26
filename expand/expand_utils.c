/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:39:36 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/26 13:22:04 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_len(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_alphanum(char c)
{
	if (c >= 48 && c <= 57)
		return (0);
	else if (c >= 65 && c <= 90)
		return (0);
	else if (c >= 97 && c <= 122)
		return (0);
	return (1);
}

int	ft_alpha(t_token *link)
{
	char	c;

	c = link->str[link->i + 1];
	if (c >= 48 && c <= 57)
		ft_rm_num(link);
	else if (c == 34 || c == 39)
		ft_rm_dollar(link);
	else if (c == '?')
		ft_quest_mark(link);
	else if (c >= 65 && c <= 90)
		return (0);
	else if (c >= 97 && c <= 122)
		return (0);
	else
		return (1);
	return (1);
}

void	ft_rm_dollar(t_token *link)
{
	int	tmp;

	tmp = link->i++;
	link->len = 2;
	ft_update_ex(link, tmp);
}
