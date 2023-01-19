/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:39:09 by abihe             #+#    #+#             */
/*   Updated: 2023/01/19 17:21:11 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_pwd(void)
{
	char	pwd[1024];

	if(getcwd(pwd, 1024) != 0)
	
		// ft_putstr_fd(pwd, 1);
		// ft_putstr_fd("\n", 1);
		printf("%s\n", pwd);
	return (ft_strdup(pwd));
}
