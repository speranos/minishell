/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:42:11 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/19 21:42:12 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_arg_len(t_token *link)
{
	int	len;

	len = 0;
	while (link && link->e_type != 1)
	{
		if (link->e_type == 0)
			len++;
		link = link->next;
	}
	return (len);
}

void	ft_init_data(t_parser **tmp, t_token **link)
{
	int	len;

	len = ft_arg_len(*link);
	*tmp = malloc(sizeof(t_parser));
	(*tmp)->redi = NULL;
	(*tmp)->args = malloc(sizeof(char *) * (len + 1));
}

void	ft_oper(t_parser **data, t_token **link)
{
	t_parser	*tmp;
	t_token		*link_tmp;
	int			len;

	len = 0;
	ft_init_data(&tmp, link);
	while (*link && (*link)->e_type != 1)
	{
		link_tmp = *link;
		if ((*link)->e_type == 0)
			tmp->args[len++] = (*link)->str;
		else if ((*link)->e_type >= 2)
			ft_add_red(&tmp, *link);
		*link = (*link)->next;
		free(link_tmp);
	}
	tmp->args[len] = 0;
	tmp->next = NULL;
	ft_add_to_link(data, link, tmp);
	if (*link != NULL)
		ft_mv_to_next(link_tmp, link, data);
}

void	ft_mv_to_next(t_token *link_tmp, t_token **link, t_parser **data)
{
	link_tmp = *link;
	*link = (*link)->next;
	free(link_tmp->str);
	free(link_tmp);
	ft_oper(data, link);
}

void	ft_add_to_link(t_parser **data, t_token **link, t_parser *tmp)
{
	t_parser	*head;

	(void)link;
	head = *data;
	if (*data == NULL)
	{
		*data = tmp;
		return ;
	}
	else
	{
		while ((*data)->next != NULL)
			*data = (*data)->next;
		(*data)->next = tmp;
		*data = head;
	}
}

void	ft_redi_add_link(t_parser **tmp, t_redi *red_tmp)
{
	t_redi	*head;

	head = (*tmp)->redi;
	if ((*tmp)->redi == NULL)
	{
		(*tmp)->redi = red_tmp;
		return ;
	}
	else
	{
		while ((*tmp)->redi->next)
			(*tmp)->redi = (*tmp)->redi->next;
		(*tmp)->redi->next = red_tmp;
		(*tmp)->redi = head;
	}
}

void	ft_add_red(t_parser **tmp, t_token *link)
{
	t_redi	*red_tmp;

	red_tmp = malloc(sizeof(t_redi));
	red_tmp->e_type = link->e_type - 2;
	red_tmp->fname = link->str;
	red_tmp->next = NULL;
	ft_redi_add_link(tmp, red_tmp);
}

void	ft_free_parser(t_parser *data)
{
	t_parser	*tmp;
	t_redi		*redi_tmp;
	t_redi		*redi;
	int			i;

	redi = data->redi;
	while (data != NULL)
	{
		redi = data->redi;
		while (redi != NULL)
		{
			redi_tmp = redi;
			free (redi_tmp->fname);
			redi = redi->next;
			free(redi_tmp);
		}
		tmp = data;
		i = 0;
		while (tmp->args[i])
			free (tmp->args[i++]);
		free(tmp->args);
		data = data->next;
		free(tmp);
	}
}

void	ft_print(t_parser *data)
{
	int		i;
	t_redi	*tmp_redi;

	i = 0;
	tmp_redi = data->redi;
	while (data != NULL)
	{
		tmp_redi = data->redi;
		while (data->args[i] != NULL)
		{
			printf("args ==========+++++ %s\n", data->args[i]);
			i++;
		}
		while (tmp_redi != NULL)
		{
			printf("filename ==>>>>>>>>> %s\n", tmp_redi->fname);
			printf("Redi_e_type ==>>>>>>>>> %d\n", tmp_redi->e_type);
			tmp_redi = tmp_redi->next;
		}
		i = 0;
		data = data->next;
	}
}
