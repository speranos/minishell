/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:26:47 by abihe             #+#    #+#             */
/*   Updated: 2023/01/24 10:33:40 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	herdoc(t_parser *data)
{
	char	*line;
	int		fd;

	fd = open("/tmp/herdc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (data->redi)
	{
		while (1)
		{
			line = readline("> ");
			if (ft_strcmp(line, data->redi->fname) == 0)
				break ;
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			free(line);
		}
		data->redi = data->redi->next;
	}
	close(fd);
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
