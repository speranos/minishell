/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:35:16 by abihe             #+#    #+#             */
/*   Updated: 2023/01/22 15:29:52 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
# include<unistd.h>


int    is_built(t_parser *tmp)
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
	int		fd[2];
	int		pid;
	int		temp_fd = 0;
	char	**env;
	char	*path;
	int tmpin = dup(0);
	int tmpout = dup(1);

	env = set_env(*envir);
	if (!data->next)
		one_node(envir, exp, data);
	else
	{
		check_herdox(data);
		while (data)
		{
			if (data->next)
				pipe(fd);
			else
				fd[1] = 1;
			if (is_built(data) == 0)
			{
				int _fd;
				_fd = ft_redirection_built_out(data);
				if (data->next && (_fd == 1 || _fd == 0))
					ft_built(envir, exp, data, fd[1]);
				else
					ft_built(envir, exp, data, _fd);
			}
			else
			{

				path = set_path(envir, data->args[0]);
				pid = fork();
				if (pid == 0)
				{
					if (data->her_doc) // iif i close fd 0 the pip will not work well
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
						break ;
				}
				else if (pid < 0)
				{
					printf("minishell: fork: Resource temporarily unavailable\n");
					break ;
				}
			}
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
		if (temp_fd != 0)
			close(temp_fd);
		dup2(tmpin, 0);
		dup2(tmpout, 1);
		while (waitpid(-1, NULL, 0) > 0);
	}
}

void    ft_built(t_envir **envir, t_envir **exp, t_parser *tmp , int fd)
{
	if (!strcmp(tmp->args[0], "pwd"))
		ft_pwd(fd);
	else if (!strcmp(tmp->args[0], "echo"))
		ft_echo(tmp->args, fd);
	else if (!strcmp(tmp->args[0], "cd"))
		ft_cd(tmp->args[1], envir, exp);
	else if (!strcmp(tmp->args[0], "exit"))
		ft_exit(tmp->args,ft_count_arg(tmp->args), fd);
	else if (!strcmp(tmp->args[0], "env"))
		ft_env_printf(*envir, fd);
	else if (!strcmp(tmp->args[0], "unset"))
		ft_unset(envir, exp, tmp->args, fd);
	else if (!strcmp(tmp->args[0], "export"))
		ft_export(exp, envir, tmp, fd);
}
