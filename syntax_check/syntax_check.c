/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:42:47 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/19 21:42:49 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_after_pipe(t_token *link)
{
	if (link->next != NULL)
	{
		link = link->next;
		if (link->e_type == 1)
		{
			ft_syntax_error();
			return (1);
		}
	}
	else
	{
		ft_syntax_error();
		return (1);
	}
	return (0);
}

int	ft_after_red(t_token *link)
{
	if (link->str[0] == '\0')
	{
		ft_syntax_error();
		return (1);
	}
	return (0);
}

int	ft_syntax_check(t_token *link)
{
	if (link->e_type == 1)
	{
		ft_syntax_error();
		return (1);
	}
	while (link)
	{
		if (link->e_type == 1 && ft_after_pipe(link) == 1)
			return (1);
		else if (link->e_type >= 2 && ft_after_red(link) == 1)
			return (1);
		link = link->next;
	}
	return (0);
}
