/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:16:34 by abihe             #+#    #+#             */
/*   Updated: 2023/01/26 23:01:25 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	node_1(t_envir **env, t_parser *data)
{
	int		pid;
	char	*path;
	int		status;

	pid = fork();
	g_params.is_process_running = 1;
	data->process_id = pid;
	if (pid == 0)
	{
		ft_redirection_in_out(data);
		if (data->her_doc)
		{
			dup2(data->herdoc_fd, 0);
			close(data->herdoc_fd);
		}
		path = set_path(env, data->args[0], 0);
		if (!path)
			exit(3);
		if (execve(path, data->args, set_env(*env)) == -1)
			exit_status(data->args[0]);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) == 0)
		g_params.ret = WEXITSTATUS(status);
	g_params.is_process_running = 0;
}

int	one_node(t_envir **env, t_envir **exp, t_parser *data)
{
	int	tmpin;
	int	tmpout;

	tmpin = dup(0);
	tmpout = dup(1);
	g_params.herdoc_dead = 0;
	check_herdox(data);
	if (g_params.herdoc_dead == 0)
	{
		if (is_built(data) == 0)
		{
			data->process_id = -1;
			ft_redirection_in_out(data);
			ft_built(env, exp, data, 1);
			g_params.ret = data->exit_status;
		}
		else
			node_1(env, data);
	}
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	return (0);
}
