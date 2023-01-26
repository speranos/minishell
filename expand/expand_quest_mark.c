/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quest_mark.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:21:39 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/26 13:21:40 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_quest_mark(t_token *link)
{
	char	*str;
	int		index;
	int		len;

	str = itoa(g_params.ret);
	index = link->i;
	len = 2;
	ft_link_update(link, str, index, len);
	free(str);
}

char	*itoa(int num)
{
	int		len;
	char	*str;

	len = ft_num_len(num);
	str = malloc(sizeof(char) * len + 1);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = (num % 10) + 48;
		num /= 10;
	}
	return (str);
}

int	ft_num_len(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}
