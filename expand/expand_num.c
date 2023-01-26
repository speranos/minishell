/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:21:31 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/26 13:21:33 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_rm_num(t_token *link)
{
	int	tmp;
	int	i;
	int	len;

	tmp = (link->i += 2);
	i = tmp;
	len = 0;
	while (link->str[i])
	{
		len++;
		i++;
	}
	ft_num_to_finstr(link, i, tmp);
}

void	ft_num_to_finstr(t_token *link, int len, int tmp)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	while (link->str[tmp])
	{
		str[i++] = link->str[tmp++];
	}
	str[i] = '\0';
	free(link->str);
	link->str = str;
	link->i = -1;
}
