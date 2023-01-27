/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:12:06 by abihe             #+#    #+#             */
/*   Updated: 2023/01/26 21:39:33 by abihe            ###   ########.fr       */
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

void	add_export(t_envir **exp, t_envir **env, char *data, char *name)
{
	if (!ft_sear_env(exp, data))
	{
		if (ft_strchr(data, '=') != NULL)
		{
			delete_node(exp, name);
			delete_node(env, name);
			ft_add_ba(exp, ft_lstnew(data));
			ft_add_ba(env, ft_lstnew(data));
		}
	}
	else if (ft_strchr(data, '='))
	{
		ft_add_ba(env, ft_lstnew(data));
		ft_add_ba(exp, ft_lstnew(data));
	}
	else
		ft_add_ba(exp, ft_lstnew(data));
}

int	exp_error(char *arg, int fd)
{
	ft_putstr_fd("minishell: export: `", fd);
	ft_putstr_fd(arg, fd);
	ft_putstr_fd("': not a valid identifier\n", fd);
	return (1);
}

int	ft_norm(int fd, t_parser *data, t_envir **exp, t_envir **env)
{
	int		size;
	char	*name;
	int		ret;
	int		i;
	int		si;

	i = 1;
	si = ft_count_arg(data->args);
	while (i < si)
	{
		size = ft_strlen(ft_strchr(data->args[i], '='));
		name = ft_substr(data->args[i], 0, ft_strlen(data->args[i]) - size);
		if (data->args[i] && !is_valid(name))
		{
			add_export(exp, env, data->args[i], name);
			ret = 0;
		}
		else
			return (exp_error(data->args[i], fd));
		free(name);
		i++;
	}
	return (ret);
}

int	ft_export(t_envir **exp, t_envir **env, t_parser *data, int fd)
{
	int		si;
	int		ret;

	si = ft_count_arg(data->args);
	ret = 0;
	if (si < 2)
	{
		sort_export(*exp);
		ft_exp_printf(*exp, fd);
	}
	else
		ret = ft_norm(fd, data, exp, env);
	return (ret);
}
