/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:07:22 by abihe             #+#    #+#             */
/*   Updated: 2023/01/23 22:08:47 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_exp_printf(t_envir *exp, int fd)
{
	while (exp)
	{
		if (ft_equal(exp->line_env))
		{
			ft_putstr_fd("declare -x ", fd);
			ft_putstr_fd(exp->line_env, fd);
			ft_putstr_fd("\n", fd);
		}
		else
		{
			ft_putstr_fd("declare -x ", fd);
			ft_putstr_fd(exp->name, fd);
			ft_putstr_fd("=\"", fd);
			ft_putstr_fd(exp->value, fd);
			ft_putstr_fd("\"\n", fd);
		}
		exp = exp->next;
	}
}
