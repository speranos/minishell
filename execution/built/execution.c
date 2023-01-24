/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:34:04 by abihe             #+#    #+#             */
/*   Updated: 2023/01/25 00:11:11 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	if_build_helper(char *path, t_envir **envir, t_parser *data, int *fd)
{
	int		temp_fd;
	char	**env;

	env = set_env(*envir);
	temp_fd = 0;
	if (data->her_doc)
		close(fd[0]);
	if (data->next)
	{
		dup2(fd[1], 1);
		close(fd[1]);
	}
	if (temp_fd != 0)
	{
		dup2(temp_fd, 0);
		close(temp_fd);
	}
	ft_redirection_in_out(data);
	if (execve(path, data->args, env) == -1)
		exit_status(data->args[0]);
	free_double(env);
}

int	if_build_in(int *fd, t_envir **envir, t_parser *data)
{
	int		pid;
	char	*path;

	path = set_path(envir, data->args[0]);
	pid = fork();
	if (pid == 0)
	{
		if_build_helper(path, envir, data, fd);
		// if (data->her_doc)
		// 	close(fd[0]);
		// if (data->next)
		// {
		// 	dup2(fd[1], 1);
		// 	close(fd[1]);
		// }
		// if (temp_fd != 0)
		// {
		// 	dup2(temp_fd, 0);
		// 	close(temp_fd);
		// }
		// ft_redirection_in_out(data);
		// if (execve(path, data->args, env) == -1)
		// 	exit_status(data->args[0]);
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
	if (data->next && (_fd == 1 || _fd == 0))
		ft_built(envir, exp, data, fd[1]);
	else
		ft_built(envir, exp, data, _fd);
}

void	execution_utils(t_envir **envir, t_envir **exp, t_parser *data)
{
	int	fd[2];
	int	temp_fd;

	temp_fd = 0;
	while (data)
	{
		if (data->next)
			pipe(fd);
		else
			fd[1] = 1;
		if (is_built(data) == 0)
			execute_build_in(fd, envir, exp, data);
		else if (if_build_in(fd, envir, data))
			break;
		if (temp_fd != 0)
			close(temp_fd);
		if (data->next)
		{
			close(fd[1]);
			temp_fd = fd[0];
		}
		else
			temp_fd = 0;
		data = data->next;
	}
}