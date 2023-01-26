/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:00:11 by abihe             #+#    #+#             */
/*   Updated: 2023/01/26 02:52:48 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	erro_exit(char *arg, int fd)
{
	ft_putstr_fd("exit\nminishell: exit: ", fd);
	ft_putstr_fd(arg, fd);
	ft_putstr_fd(": numeric argument required \n", fd);
	exit(255);
}

int	ft_exit(char **arg, int argc, int fd)
{
	int	i;

	i = 0;
	if (argc == 1)
	{
		ft_putstr_fd("exit\n", fd);
		exit(0);
	}
	while (i < argc)
	{
		if (!is_number(arg[1]) && argc == 2)
			exit(atoi(arg[1]));
		else if (is_number(arg[1]))
			erro_exit(arg[1], fd);
		else if (!is_number(arg[1]) && argc > 2)
		{
			ft_putstr_fd("exit\nminishell: exit: too many arguments\n", fd);
			return (1);
		}
		i++;
	}
	return (0);
}
