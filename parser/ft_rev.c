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
	(*tmp)->redi = malloc(sizeof(t_redi));
	(*tmp)->args = malloc(sizeof(char *) * (len + 1));
	(*tmp)->redi->fname = 0;
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

	int i = 0;

	data = NULL;
	ft_oper(&data, &link);
	while (data != NULL)
	{
		printf("HSPPHGPHSHG\n");
		while (data->args[i] != NULL)
		{
			printf("data_filename ==>>>>>>>>> %s\n", data->redi->fname);
			printf("data->args ========== %s\n", data->args[i]);
			i++;
		}
		i = 0;
		data = data->next;
	}
}

void	ft_add_red(t_parser **tmp, t_token *link)
{
	(*tmp)->redi->type = link->type - 2;
	(*tmp)->redi->fname = link->str;
}
