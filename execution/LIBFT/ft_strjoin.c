/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:14:32 by abihe             #+#    #+#             */
/*   Updated: 2023/01/24 15:53:59 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*d;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	d = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!d)
		return (0);
	i = 0;
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		d[i++] = s2[j++];
	d[i] = '\0';
	return (d);
}
