/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:35:16 by abihe             #+#    #+#             */
/*   Updated: 2023/01/25 00:12:31 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_built(t_parser *tmp)
{
	if (!ft_strcmp(tmp->args[0], "pwd"))
		return (0);
	else if (!ft_strcmp(tmp->args[0], "echo"))
		return (0);
	else if (!ft_strcmp(tmp->args[0], "cd"))
		return (0);
	else if (!ft_strcmp(tmp->args[0], "exit"))
		return (0);
	else if (!ft_strcmp(tmp->args[0], "env"))
		return (0);
	else if (!ft_strcmp(tmp->args[0], "unset"))
		return (0);
	else if (!ft_strcmp(tmp->args[0], "export"))
		return (0);
	else
		return (1);
}

int	size_list(t_parser *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

char	**set_env(t_envir *env)
{
	int		i;
	char	**str;
	t_envir	*tmp;

	i = 0;
	tmp = env;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	str = malloc(sizeof(char *) * (i + 1));
	i = 0;
	tmp = env;
	while (tmp)
	{
		str[i] = ft_strdup(tmp->line_env);
		tmp = tmp->next;
		i++;
	}
	str[i] = NULL;
	return (str);
}

void	ft_execution(t_envir **envir, t_envir **exp, t_parser *data)
{
	int		temp_fd;
	int		tmpin;
	int		tmpout;

	temp_fd = 0;
	tmpin = dup(0);
	tmpout = dup(1);
	if (!data->next)
		one_node(envir, exp, data);
	else
	{
		check_herdox(data);
		execution_utils(envir, exp, data);
		if (temp_fd != 0)
			close(temp_fd);
		dup2(tmpin, 0);
		dup2(tmpout, 1);
		while (waitpid(-1, NULL, 0) > 0);
	}
}

void	ft_built(t_envir **envir, t_envir **exp, t_parser *tmp, int fd)
{
	char *pwd;

	if (!strcmp(tmp->args[0], "pwd"))
	{
		pwd = ft_pwd(*envir);
		ft_putstr_fd(pwd, fd);
		write(fd, "\n", 1);
		free(pwd);
	}
	else if (!strcmp(tmp->args[0], "echo"))
		ft_echo(tmp->args, fd);
	else if (!strcmp(tmp->args[0], "cd"))
		ft_cd(tmp->args[1], envir, exp);
	else if (!strcmp(tmp->args[0], "exit"))
		ft_exit(tmp->args, ft_count_arg(tmp->args), fd);
	else if (!strcmp(tmp->args[0], "env"))
		ft_env_printf(*envir, fd);
	else if (!strcmp(tmp->args[0], "unset"))
		ft_unset(envir, exp, tmp->args, fd);
	else if (!strcmp(tmp->args[0], "export"))
		ft_export(exp, envir, tmp, fd);
}
