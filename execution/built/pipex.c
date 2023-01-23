// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   pipex.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/05/24 23:16:34 by abihe             #+#    #+#             */
// /*   Updated: 2023/01/14 17:59:21 by abihe            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

 #include "../../minishell.h"

int		one_node(t_envir **env, t_envir **exp, t_parser *data)
{
	int		pid;
	char	*path;
	int tmpin = dup(0);
	int tmpout = dup(1);

	check_herdox(data);
	path = set_path(env,data->args[0]);

	if (is_built(data) == 0)
	{
		ft_redirection_in_out(data);
		ft_built(env, exp, data, 1);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			// if(data->her_doc == 1)
			// 	printf("here\n");
			ft_redirection_in_out(data);
			if (data->her_doc)
			{
				dup2(data->herdoc_fd, 0);
				close(data->herdoc_fd);
			}
			if (!path)
				exit(3);
			if (execve(path, data->args, set_env(*env)) == -1)
			{
				ft_putstr_fd("Minishell: ", 2);
				ft_putstr_fd(path, 2);
				ft_putstr_fd(": command not found\n", 2);
				exit(1);
			}
		}
		waitpid(pid, NULL, 0);
	}
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	return (0);
}
