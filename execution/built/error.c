/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:56:02 by abihe             #+#    #+#             */
/*   Updated: 2023/01/24 12:22:08 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include <dirent.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_error(char *str, char *arg, char *str2, int ex)
{
	ft_putstr(str);
	ft_putstr(arg);
	ft_putstr(str2);
	exit (ex);
}

void	exit_status(char *str)
{
	DIR		*dir;
	
	dir = opendir(str);
	if (str[0] == '/' && dir == NULL)
		ft_error("minishell: ", str, ": No such file or directory\n", 127);
	else if (dir && ft_strchr(str, '/'))
	{
		closedir(dir);	
		ft_error("minishell: ", str, ": is a directory\n", 126);
	}
	else if (!dir && ft_strchr(str, '/'))
		ft_error("minishell: ", str, ": Not a directory\n", 126);
	else
		ft_error("minishell: ", str, ": command not found\n", 127);
}
