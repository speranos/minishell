/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:26:47 by abihe             #+#    #+#             */
/*   Updated: 2023/01/25 12:20:39 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	herdoc(t_parser *data)
{
	char	*line;
	int		fd;

	fd = open("/tmp/herdc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	g_params.is_heredoc_running = 1;
	g_params.inputfd = dup(0);
	while (data->redi)
	{
		while (1)
		{
			ft_putstr_fd(">", 1);
			line = get_next_line(g_params.inputfd);
			if (!line)
				break ;
			if (ft_strcmp(line, data->redi->fname) == 0)
			{
				free(line);
				break ;
			}
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			free(line);
		}
		free(data->redi->fname);
		data->redi = data->redi->next;
	}
	close(fd);
	g_params.is_heredoc_running = 0;
	if (g_params.inputfd != -1)
		close(g_params.inputfd);
	fd = open("/tmp/herdc.txt", O_RDWR, 0644);
	// dup2(fd, 0);
	// close(fd);
	return (fd);
}

void	check_herdox(t_parser *data)
{
	t_redi	*temp;

	while (data)
	{
		temp = data->redi;
		data->her_doc = 0;
		while (temp)
		{
			if (temp->e_type == 2)
			{
				data->her_doc = 1;
				data->herdoc_fd = herdoc(data);
			}
			temp = temp->next;
		}
		data = data->next;
	}
}
