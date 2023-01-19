/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:41:53 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/19 21:41:55 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_token(int type, char *str)
{
	t_token	*next_node;

	next_node = malloc(sizeof(t_token));
	next_node->str = str;
	next_node->e_type = type;
	next_node->next = NULL;
	return (next_node);
}

void	ft_syntax_error(void)
{
	printf("minishell: syntax...error...\n");
}
