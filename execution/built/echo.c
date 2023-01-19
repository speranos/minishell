/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:32:54 by abihe             #+#    #+#             */
/*   Updated: 2023/01/19 16:54:31 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_n(char *arg)
{
	int	i;
	int	len;

	len = 0;
	len = strlen(arg);
	i = 0;
	if (strcmp(arg, "") == 0)
		return (1);
	if (arg[i] == '-')
	{
		i++;
		while (arg[i] && arg[i] == 'n')
			i++;
	}
	if (i == len)
		return (0);
	else
		return (1);
}

void	echo_arg(char **arg, int *f, int fd)
{
	int	j;

	j = 1;
	while (arg[j] && check_n(arg[j]) == 0)
	{
		*f = 1;
		j++;
	}
	while (arg[j])
	{
		ft_putstr_fd(arg[j], fd);
		j++;
		if (arg[j])
			ft_putstr_fd(" ", fd);
	}
}

char	*ft_echo(char **arg,int fd)
{
	int	f;

	f = 0;
	echo_arg(arg, &f, fd);
	if (f == 0)
		ft_putstr_fd("\n", fd);
	return ("");
}
