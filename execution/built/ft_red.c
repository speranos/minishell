/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:28:51 by abihe             #+#    #+#             */
/*   Updated: 2023/01/24 23:09:40 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_redirection_in_out(t_parser *data)
{
	int fdin = 0;
    int fdout = 0;

	while (data->redi)
	{
		//input 
		if(data->redi->e_type == 0) // input
		{
			fdin = open(data->redi->fname, O_RDONLY);
			if (fdin < 0)
            {
				printf("Minishell: %s:  No such file or directory\n",data->redi->fname);
                exit (1);
            }
			// if (fdin != 0)
			// 	close(fdin);
			// data->_fdin = fdin;
			dup2(fdin, 0);
			close(fdin);
		}
		else if(data->redi->e_type == 1)
		{
			if (fdout > 0)
				close(fdout);
			fdout = open(data->redi->fname, O_WRONLY|O_CREAT|O_TRUNC, 0644);
			if (access(data->redi->fname, R_OK))
				printf("Error : Permission denied\n");\
			dup2(fdout, 1);
			close(fdout);
		}
		else if (data->redi->e_type == 3)
		{
			if (fdout > 0)
				close(fdout);
			fdout = open(data->redi->fname, O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (access(data->redi->fname, R_OK))
				printf("Error : Permission denied\n");
			dup2(fdout, 1);
			close(fdout);
		}
		data->redi = data->redi->next;
	}
	return (fdout);
}

int	ft_redirection_built_out(t_parser *data)
{
    int fdout = 1;
    int fdin = 0;

	while (data->redi)
	{
		if(data->redi->e_type == 1)
		{
			if (fdout > 1)
				close(fdout);
			fdout = open(data->redi->fname, O_WRONLY|O_CREAT|O_TRUNC, 0644);
			if (access(data->redi->fname, R_OK))
				printf("Error : Permission denied\n");
		}
		else if (data->redi->e_type == 3)
		{
			if (fdout > 1)
				close(fdout);
			fdout = open(data->redi->fname, O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (access(data->redi->fname, R_OK))
				printf("Error : Permission denied\n");
		}
		else if (data->redi->e_type == 2)
		{
			int fd;
			fd = herdoc(data);
			return (1);
		}
		else if (data->redi->e_type == 0)
		{
			fdin = open(data->redi->fname, O_RDONLY);
			if (fdin < 0)
            {
				printf("Minishell: %s:  No such file or directory\n",data->redi->fname);
                return (-1);
            }
		}
		data->redi = data->redi->next;
	}

	return (fdout);
}