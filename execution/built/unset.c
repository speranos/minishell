/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:40:02 by abihe             #+#    #+#             */
/*   Updated: 2023/01/25 12:59:04 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_check_alpha(char *word)
{
	int	i;

	i = 0;
	while (word[i])
	{
		if ((word[i] >= 65 && word[i] <= 90)
			|| (word[i] >= 97 && word[i] <= 122)
			|| (word[i] >= 48 && word[i] <= 57))
			i++;
		else
			return (1);
	}
	return (0);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9') || str[i] == '_')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_sear_env(t_envir **envir, char *arg)
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
		{
			free(name);
			return (0);
		}
		tmp = (tmp)->next;
	}
	free(name);
	return (1);
}

int	ft_unset(t_envir **envir, t_envir **exp, char **arg, int fd)
{
	int		j;
	t_envir	*tmp;

	j = 1;
	tmp = *envir;
	while (arg[j])
	{
		if (is_valid(arg[j]))
		{
			ft_putstr_fd("minishell: unset: `", fd);
			ft_putstr_fd(arg[j], fd);
			ft_putstr_fd("': not a valid identifier\n", fd);
		}
		else if (!ft_sear_env(envir, arg[j]) || !ft_sear_env(exp, arg[j]))
		{
			delete_node(envir, arg[j]);
			delete_node(exp, arg[j]);
		}
		j++;
	}
	return (0);
}
