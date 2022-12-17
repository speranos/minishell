#include "../minishell.h"

int	ft_arg_len(t_token *link)
{
	int	len;

	len = 0;
	while (link && link->type != 1)
	{
		if(link->type == 0)
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

t_parser	*ft_oper(t_parser **data, t_token **link)
{
	t_parser	*tmp;
	int	len;

	len = 0;
	ft_init_data(&tmp, link);
	while (*link && (*link)->type != 1)
	{
		if((*link)->type == 0)
				tmp->args[len++] = (*link)->str;
		else if((*link)->type >= 2)
			ft_add_red(&tmp, *link);
		*link = (*link)->next;
	}
	tmp->args[len] = 0;
	tmp->next = NULL;
	ft_add_to_link(data, link, tmp);
	if(*link != NULL)
	{
		*link = (*link)->next;
		ft_oper(data, link);
	}
	return (tmp);
}

void	ft_add_to_link(t_parser **data, t_token **link, t_parser *tmp)
{
	t_parser	*head;
	(void)link;

	head = *data;
	if(*data == NULL)
	{
		*data = tmp;
		return;
	}
	else
	{
		while((*data)->next != NULL)
			*data = (*data)->next;
		(*data)->next = tmp;
		*data = head;
	}
}

void	ft_rev(t_token *link)
{
	t_parser	*data;

	data = NULL;
	ft_oper(&data, &link);
	ft_print(data);
	t_redi	*tmp;
	while(data->redi != NULL)
	{
		tmp = data->redi;
		free(tmp->fname);
		free(tmp);
		data->redi = data->redi->next;
	}
	//ft_free_redi(data->redi);
	ft_free_parser(data);
}

void	ft_redi_add_link(t_parser **tmp, t_redi *red_tmp)
{
	t_redi	*head;

	head = (*tmp)->redi;
	if((*tmp)->redi == NULL)
	{
		(*tmp)->redi = red_tmp;
		return;
	}
	else
	{
		while((*tmp)->redi->next)
			(*tmp)->redi = (*tmp)->redi->next;
		(*tmp)->redi->next = red_tmp;
		(*tmp)->redi = head;
	}
}

void	ft_add_red(t_parser **tmp, t_token *link)
{
	t_redi	*red_tmp;

	red_tmp = malloc(sizeof(t_redi));
	red_tmp->type = link->type - 2;
	red_tmp->fname = link->str;
	red_tmp->next = NULL;
	ft_redi_add_link(tmp, red_tmp);
}

void	ft_free_parser(t_parser *data)
{
	t_parser	*tmp;

	while(data != NULL)
	{
		tmp = data;
		free(tmp->args);
		free(tmp);
		data = data->next;
	}
}

void	ft_free_redi(t_redi *redi)
{
	t_redi	*tmp;

	while(redi != NULL)
	{
		tmp = redi;
		free(tmp->fname);
		free(tmp);
		redi = redi->next;
	}
}

void	ft_print(t_parser *data)
{
	int	i;

	i = 0;
	while (data != NULL)
	{
		while (data->args[i] != NULL)
		{
			printf("args ==========+++++ %s\n", data->args[i]);
			i++;
		}
		while (data->redi != NULL)
		{
			printf("filename ==>>>>>>>>> %s\n", data->redi->fname);
			data->redi = data->redi->next;
		}
		i = 0;
		data = data->next;
	}
}