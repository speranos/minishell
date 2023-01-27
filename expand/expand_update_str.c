/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_update_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:21:48 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/26 22:12:12 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_update_ex(t_token *link, int tmp, t_envir *envir)
{
	char	*str;
	char	*get_str;
	int		i;
	int		index;

	index = tmp;
	i = 0;
	str = malloc(sizeof(char) * link->len);
	tmp++;
	while (tmp < link->i)
	{
		str[i++] = link->str[tmp++];
	}
	str[i] = '\0';
	get_str = get_env(str, envir);
	i++;
	ft_link_update(link, get_str, index, i);
	free(str);
	free(get_str);
}

void	ft_link_update(t_token *link, char *str, int index, int def)
{
	char	*fin_str;

	fin_str = ft_to_fin_str(link, str, index, def);
	free(link->str);
	link->str = fin_str;
	link->index = 0;
}

char	*ft_to_fin_str(t_token *link, char *str, int index, int def)
{
	int		str_len;
	int		link_len;
	char	*fin_str;

	fin_str = malloc(sizeof(char) * (ft_fin_len(link, str, def) + 1));
	str_len = 0;
	link_len = 0;
	link->len = 0;
	while (link->str[link_len])
	{
		if (link_len == index)
		{
			if (str != NULL)
			{
				while (str[str_len] != '\0')
					fin_str[link->len++] = str[str_len++];
			}
			link_len += def;
		}
		else
			fin_str[link->len++] = link->str[link_len++];
	}
	fin_str[link->len] = '\0';
	return (fin_str);
}

int	ft_fin_len(t_token *link, char *str, int def)
{
	int		link_len;
	int		str_len;
	int		len;

	link_len = ft_len(link->str);
	str_len = ft_len(str);
	len = (link_len - (def)) + str_len;
	return (len);
}
