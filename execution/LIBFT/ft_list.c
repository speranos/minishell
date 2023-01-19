/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:32:04 by abihe             #+#    #+#             */
/*   Updated: 2023/01/04 10:36:09 by abihe            ###   ########.fr       */
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
	int     size;

	node = malloc(sizeof(t_envir));
	if (!node)
		return (0);
	node->line_env = ft_strdup(line);
	size = ft_strlen(ft_strchr(line, '='));
	node->name = ft_substr(line, 0, ft_strlen(line) - size);
	node->value = ft_substr(line, ft_strlen(line) - size + 1, ft_strlen(line));
	// printf("Size : %d || len : %zu\n", size, ft_strlen(line));
	node->next = NULL;
	return (node);
}

void    delete_node(t_envir **env, char *name)
{
    t_envir    *tmp;
    t_envir    *prev;

    tmp = *env;
    if (tmp && !(ft_strcmp(tmp->name, name)))
    {
        (*env) = (*env)->next;
        free(tmp->name);
        free(tmp->value);
        free(tmp->line_env);
        free(tmp);
        return ;
    }
    else
    {
        while (tmp)
        {
            if (!ft_strcmp(tmp->name, name))
            {
                prev->next = tmp->next;
				free(tmp->name);
        		free(tmp->value);
        		free(tmp->line_env);
                free(tmp);
                break ;
            }
            prev = tmp;
            tmp = tmp->next;
        }
    }
}