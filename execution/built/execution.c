/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:34:04 by abihe             #+#    #+#             */
/*   Updated: 2023/01/26 20:48:06 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**child_proc(t_envir **envir, t_parser *data, int *fd, int *temp_fd)
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

int	exec_p(int *fd, t_envir **envir, t_parser *data, int *temp_fd)
{
	int		pid;
	char	*path;
	char	**env;

	pid = fork();
	path = NULL;
	g_params.is_process_running = 1;
	data->process_id = pid;
	if (pid == 0)
	{
		path = set_path(envir, data->args[0], 0);
		env = child_proc(envir, data, fd, temp_fd);
		if (execve(path, data->args, set_env(*envir)) == -1)
		{
			dup2(temp_fd[0], 1);
			dup2(temp_fd[1], 0);
			exit_status(data->args[0]);
		}
	}
	else if (pid < 0 && printf("mshell: fork: Resource temp unavailable\n"))
	{
		free(path);
		return (1);
	}
	return (0);
}

void	built_p(int *fd, t_envir **envir, t_envir **exp, t_parser *data)
{
	int	_fd;

	_fd = ft_redirection_built_out(data);
	data->process_id = -1;
	if (data->next && (_fd == 1 || _fd == 0))
		ft_built(envir, exp, data, fd[1]);
	else
		ft_built(envir, exp, data, _fd);
}

void	mul_pip(t_envir **envir, t_envir **exp, t_parser *data, int *temp_fd)
{
	int	fd[2];

	while (data)
	{
		if (data->next)
			pipe(fd);
		else
			fd[1] = 1;
		if (is_built(data) == 0)
			built_p(fd, envir, exp, data);
		else if (exec_p(fd, envir, data, temp_fd))
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
