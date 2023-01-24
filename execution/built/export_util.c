/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:07:22 by abihe             #+#    #+#             */
/*   Updated: 2023/01/24 10:14:46 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

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

void	ft_swap_data(t_envir *exp)
{
	char	*tmp1;

	tmp1 = exp->line_env;
	exp->line_env = exp->next->line_env;
	exp->next->line_env = tmp1;
	tmp1 = exp->name;
	exp->name = exp->next->name;
	exp->next->name = tmp1;
	tmp1 = exp->value;
	exp->value = exp->next->value;
	exp->next->value = tmp1;
}

void	sort_export(t_envir *exp)
{
	int		i;
	int		size;
	t_envir	*exp_tmp;

	i = 0;
	size = ft_lstsize(exp);
	exp_tmp = exp;
	while (i < size)
	{
		exp = exp_tmp;
		while (exp->next)
		{
			if (ft_strcmp(exp->line_env, exp->next->line_env) > 0)
				ft_swap_data(exp);
			exp = exp->next;
		}
		i++;
	}
}
