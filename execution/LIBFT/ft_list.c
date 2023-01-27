/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:38:02 by abihe             #+#    #+#             */
/*   Updated: 2023/01/26 21:29:50 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_lstsize(t_envir *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	ft_add_ba(t_envir **list, t_envir *new)
{
	t_envir	*tmp;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_add_front(t_envir *var, t_envir *new)
{
	new->next = var;
	var = new;
}

t_envir	*ft_lstnew(char *line)
{
	t_envir	*node;
	int		size;

	node = malloc(sizeof(t_envir));
	if (!node)
		return (0);
	node->line_env = ft_strdup(line);
	size = ft_strlen(ft_strchr(line, '='));
	node->name = ft_substr(line, 0, ft_strlen(line) - size);
	node->value = ft_substr(line, ft_strlen(line) - size + 1, ft_strlen(line));
	node->next = NULL;
	return (node);
}
