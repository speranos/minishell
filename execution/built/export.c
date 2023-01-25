/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:12:06 by abihe             #+#    #+#             */
/*   Updated: 2023/01/25 13:46:35 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_count_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
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

int	ft_export(t_envir **exp, t_envir **env, t_parser *data, int fd)
{
	int		si;
	int		i;
	int		size;
	char	*name;
	int		ret;

	i = 1;
	si = ft_count_arg(data->args);
	ret = 0;
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
			{
				add_export(exp, env, data, name, i);
				ret = 0;
			}
			else
				return (exp_error(data->args[i], fd));
			free(name);
			i++;
		}
	}
	return (ret);
}
