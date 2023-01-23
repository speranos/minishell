/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:12:06 by abihe             #+#    #+#             */
/*   Updated: 2023/01/22 15:16:33 by abihe            ###   ########.fr       */
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

int	ft_count_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
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

void	add_export(t_envir **exp, t_envir **env, t_parser *data, char *name, int i)
{
	if (!ft_sear_env(exp, data->args[i]))
	{
		if (ft_strchr(data->args[i], '=') != NULL)
		{
			delete_node(exp, name);
			delete_node(env, name);
			ft_add_ba(exp, ft_lstnew(data->args[i]));
			ft_add_ba(env, ft_lstnew(data->args[i]));
		}
	}
	else if (ft_strchr(data->args[i], '='))
	{
		ft_add_ba(env, ft_lstnew(data->args[i]));
		ft_add_ba(exp, ft_lstnew(data->args[i]));
	}
	else
		ft_add_ba(exp, ft_lstnew(data->args[i]));
}

int	exp_error(char *arg, int fd)
{
	ft_putstr_fd("minishell: export: `", fd);
	ft_putstr_fd(arg, fd);
	ft_putstr_fd("': not a valid identifier\n", fd);
	return (1);
}

void	ft_export(t_envir **exp, t_envir **env, t_parser *data, int fd)
{
	int		si;
	int		i;
	int		size;
	char	*name;

	i = 1;
	si = ft_count_arg(data->args);
	if (si < 2)
	{
		sort_export(*exp);
		ft_exp_printf(*exp, fd);
	}
	else
	{
		while (i < si)
		{
			size = ft_strlen(ft_strchr(data->args[i], '='));
			name = ft_substr(data->args[i], 0, ft_strlen(data->args[i]) - size);
			if (data->args[i] && !is_valid(name))
				add_export(exp, env, data, name, i);
			else
				exp_error(data->args[i], fd);
			i++;
		}
	}
}
