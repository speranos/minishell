/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:39:29 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/25 12:31:41 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_expand(t_token *link)
{
	while (link)
	{
		if (link->e_type == 0 || link->e_type >= 2)
			ft_check(link);
		link = link->next;
	}
}

void	ft_check(t_token *link)
{
	link->index = 0;
	link->i = 0;
	while (link->str[link->i])
	{
		if (link->str[link->i] == 36)
			ft_dollar(link);
		else if (link->str[link->i] == 34)
			link->index++;
		else if (link->str[link->i] == 39 && (link->index == 0
				|| link->index % 2 == 0))
			ft_single(link);
		link->i++;
	}
}

void	ft_single(t_token *link)
{
	char	c;

	c = link->str[link->i];
	link->i++;
	while (link->str[link->i] && link->str[link->i] != c)
	{
		if (link->str[link->i] == 34)
			link->index++;
		link->i++;
	}
	if(link->str[link->i] == '\0')
		link->i--;
}

void	ft_dollar(t_token *link)
{
	int		tmp;
	char	c;

	tmp = 0;
	c = link->str[link->i + 1];
	if (ft_alpha(link) == 1)
		return ;
	tmp = link->i++;
	while (link->str[link->i] && ft_alphanum(c) != 1)
			c = link->str[++link->i];
	link->len = link->i - tmp;
	ft_update_ex(link, tmp);
	link->i = -1;
}

void	ft_update_ex(t_token *link, int tmp)
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
	get_str = getenv(str);
	i++;
	ft_link_update(link, get_str, index, i);
	free(str);
}

void	ft_link_update(t_token *link, char *str, int index, int def)
{
	char	*fin_str;

	fin_str = ft_to_fin_str(link, str, index, def);
	free(link->str);
	link->str = fin_str;
	link->index = 0;
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

int	ft_len(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_alphanum(char c)
{
	if (c >= 48 && c <= 57)
		return (0);
	else if (c >= 65 && c <= 90)
		return (0);
	else if (c >= 97 && c <= 122)
		return (0);
	return (1);
}

int	ft_alpha(t_token *link)
{
	char	c;

	c = link->str[link->i + 1];
	if (c >= 48 && c <= 57)
		ft_rm_num(link);
	else if (c == 34 || c == 39)
		ft_rm_dollar(link);
	else if (c == '?')
	{
		// printf("WEHWERRHW\n");
		ft_quest_mark(link);
	}
	else if (c >= 65 && c <= 90)
		return (0);
	else if (c >= 97 && c <= 122)
		return (0);
	else
		return (1);
	return (1);
}

void	ft_num_to_finstr(t_token *link, int len, int tmp)
{
	char	*str;
	int		i = 0;

	str = malloc(sizeof(char) * (len + 1));
	while(link->str[tmp])
	{
		str[i++] = link->str[tmp++];
	}
	str[i] = '\0';
	free(link->str);
	link->str = str;
	link->i = -1;
}

void	ft_rm_num(t_token *link)
{
	int	tmp;

	tmp = link->i += 2;
	int i = tmp;
	int len = 0;
	while(link->str[i])
	{
		len++;
		i++;
	}
	ft_num_to_finstr(link, i, tmp);
}

void	ft_rm_dollar(t_token *link)
{
	int	tmp;

	tmp = link->i++;
	link->len = 2;
	ft_update_ex(link, tmp);
}

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
