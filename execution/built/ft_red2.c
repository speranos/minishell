/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:55:43 by abihe             #+#    #+#             */
/*   Updated: 2023/01/25 19:48:19 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// void	red_b0(t_parser *data, int fdin)
// {
// 	fdin = open(data->redi->fname, O_RDONLY);
// 	if (fdin < 0)
// 	{
// 		printf("Minishell: %s:  No such file or directory\n", data->redi->fname);
//         printf("roma\n");
// 	}
// }

// void	red_b1(t_parser *data, int fdout)
// {
// 	if (fdout > 1)
// 		close(fdout);
// 	fdout = open(data->redi->fname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (access(data->redi->fname, R_OK))
// 		printf("Error : Permission denied\n");
// }

// void	red_b3(t_parser *data, int fdout)
// {
// 	if (fdout > 1)
// 		close(fdout);
// 	fdout = open(data->redi->fname, O_WRONLY | O_CREAT | O_APPEND, 0644);
// 	if (access(data->redi->fname, R_OK))
// 		printf("Error : Permission denied\n");
// }

// int	ft_redirection_built_out(t_parser *data)
// {
// 	int	fdout;
// 	int	fdin;
//     int	fd;

// 	fdout = 1;
// 	fdin = 0;
// 	while (data->redi)
// 	{
// 		if (data->redi->e_type == 0)
// 			red_b0(data, fdin);
// 		else if (data->redi->e_type == 1)
// 			red_b1(data, fdout);
// 		else if (data->redi->e_type == 2)
// 			{
//                 fd = herdoc(data);
// 	            return (1);
//             }
// 		else if (data->redi->e_type == 3)
// 			red_b3(data, fdout);
// 		data->redi = data->redi->next;
// 	}
// 	return (fdout);
// }
