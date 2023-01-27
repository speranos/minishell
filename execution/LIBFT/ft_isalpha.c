/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:39:35 by abihe             #+#    #+#             */
/*   Updated: 2023/01/26 21:29:09 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../minishell.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

void	free_ftlist(t_envir **env, t_envir	*tmp)
{
	(*env) = (*env)->next;
	free(tmp->name);
	free(tmp->value);
	free(tmp->line_env);
	free(tmp);
}

void	delete_node(t_envir **env, char *name)
{
	t_envir	*tmp;
	t_envir	*prev;

	tmp = *env;
	if (tmp && !(ft_strcmp(tmp->name, name)))
		free_ftlist(env, tmp);
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
