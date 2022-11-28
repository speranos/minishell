#include "../minishell.h"

t_token	*ft_token(int type, char *str)
{
	t_token	*next_node;

	next_node = malloc(sizeof(t_token));
	next_node->str = str;
	next_node->type = type;
	next_node->next = NULL;
	return next_node;
}

void	ft_syntax_error(void)
{
	printf("minishell: syntax...error...\n");
}