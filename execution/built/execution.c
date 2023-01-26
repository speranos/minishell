/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:34:04 by abihe             #+#    #+#             */
/*   Updated: 2023/01/26 02:52:38 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**if_build_helper(t_envir **envir, t_parser *data, int *fd, int *temp_fd)
{
	char	**env;

	env = set_env(*envir);
	if (data->her_doc)
	{
		close(fd[0]);
		close(*temp_fd);
		*temp_fd = data->herdoc_fd;
	}
	if (data->next)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
	}
	if (*temp_fd != 0)
	{
		dup2(*temp_fd, 0);
		close(*temp_fd);
	}
	ft_redirection_in_out(data);
	return (env);
}

int	if_build_in(int *fd, t_envir **envir, t_parser *data, int *temp_fd)
{
	int		pid;
	char	*path;
	char	**env;

	path = set_path(envir, data->args[0], 0);
	pid = fork();
	g_params.is_process_running = 1;
	data->process_id = pid;
	if (pid == 0)
	{
		env = if_build_helper(envir, data, fd, temp_fd);
		if (execve(path, data->args, env) == -1)
		{
			free_double(env);
			exit(1);
			exit_status(data->args[0]);
		}
	}
	else if (pid < 0)
	{
		printf("minishell: fork: Resource temporarily unavailable\n");
		free(path);
		return (1);
	}
	free(path);
	return (0);
}

void	execute_build_in(int *fd, t_envir **envir, t_envir **exp, t_parser *data)
{
	int	_fd;

	_fd = ft_redirection_built_out(data);
	data->process_id = -1;
	if (data->next && (_fd == 1 || _fd == 0))
		ft_built(envir, exp, data, fd[1]);
	else
		ft_built(envir, exp, data, _fd);
}

void	execution_utils(t_envir **envir, t_envir **exp, t_parser *data, int *temp_fd)
{
	int	fd[2];

	while (data)
	{
		if (data->next)
			pipe(fd);
		else
			fd[1] = 1;
		if (is_built(data) == 0)
			execute_build_in(fd, envir, exp, data);
		else if (if_build_in(fd, envir, data, temp_fd))
			break ;
		if (*temp_fd != 0)
			close(*temp_fd);
		if (data->next)
		{
			close(fd[1]);
			*temp_fd = fd[0];
		}
		else
			*temp_fd = 0;
		data = data->next;
	}
}
