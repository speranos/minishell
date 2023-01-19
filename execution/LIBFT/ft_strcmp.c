/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:10:40 by abel-bou          #+#    #+#             */
/*   Updated: 2023/01/18 23:12:29 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;

	if (!s1 || !s2)
		return (1);
	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	i = 0;
	if (cast_s1[i] == '\0' && cast_s2[i] == '\0')
		return (0);
	while ((cast_s1[i] || cast_s2[i]))
	{
		if (cast_s1[i] != cast_s2[i])
			return (cast_s1[i] - cast_s2[i]);
		i++;
	}
	return (0);
}
