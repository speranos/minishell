/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:40:02 by abihe             #+#    #+#             */
/*   Updated: 2023/01/19 18:36:30 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_check_alpha(char *word)
{
	int	i;

	i = 0;
	while (word[i])
	{
		if ((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122) || (word[i] >= 48 && word[i] <= 57))
			i++;
		else
			return (1);
	}
	return (0);
}

int ft_sear_env(t_envir **envir,char *arg)
{
	t_envir	*tmp;
	char	*name;
	int		size;

	tmp = *envir;
	size = ft_strlen(ft_strchr(arg, '='));
	name = ft_substr(arg, 0, ft_strlen(arg) - size);
	
	while (tmp)
	{
		if (!ft_strcmp(name, (tmp)->name))
			return(0);
		tmp = (tmp)->next;
	}
	return (1);
}

void	ft_unset(t_envir **envir, t_envir **exp, char **arg, int fd)
{
	int		j;
	t_envir	*tmp;

	j = 1;
	tmp = *envir;
	while (arg[j])
	{
		if (!ft_isdigit(arg[j][0]) || ft_check_alpha(arg[j]))
		{
			ft_putstr_fd("minishell: unset: `", fd);
			ft_putstr_fd(arg[j], fd);
			ft_putstr_fd("': not a valid identifier\n", fd);
		}
		else if (!ft_sear_env(envir,arg[j]) || !ft_sear_env(exp,arg[j]))
		{
			// printf("l9itha\n");
			delete_node(envir, arg[j]);
			delete_node(exp, arg[j]);
		}
		j++;
	}
}