/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:06:43 by abihe             #+#    #+#             */
/*   Updated: 2023/01/14 18:00:16 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	a;
	size_t	b;

	if (s == 0)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ss = (char *) malloc(sizeof(char) * (len + 1));
	if (!ss)
		return (0);
	a = 0;
	b = 0;
	while (a < (size_t) ft_strlen(s))
	{
		if (a >= start && b < len)
		{
			ss[b] = s[a];
			b++;
		}
		a++;
	}
	ss[b] = '\0';
	return (ss);
}
