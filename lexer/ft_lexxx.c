/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:55:05 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/26 22:12:29 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_link(t_token *link)
{
	t_token	*node;

	while (link != NULL)
	{
		node = link;
		free(link->str);
		link = link->next;
		free(node);
	}
}

void	ft_add_back(t_token **link, t_token *node)
{
	t_token	*head;

	head = *link;
	if (*link == NULL)
	{
		*link = node;
		return ;
	}
	else
	{
		while ((*link)->next != NULL)
			*link = (*link)->next;
		(*link)->next = node;
		*link = head;
	}
}

void	ft_lexxx_init(t_lexer *lexer)
{
	lexer->i = 0;
	lexer->quotes = 0;
	lexer->c = lexer->input[lexer->i];
}

t_parser	*ft_lexxx(char *input, t_envir *envir)
{
	t_lexer		lexer;
	t_token		*node;
	t_token		*link;
	t_parser	*data;

	data = NULL;
	link = NULL;
	lexer.input = input;
	ft_lexxx_init(&lexer);
	while (lexer.input[lexer.i])
	{
		node = ft_searche(&lexer);
		ft_add_back(&link, node);
	}
	if (lexer.quotes != 0 || ft_syntax_check(link) == 1)
	{
		ft_free_link(link);
		return (NULL);
	}
	ft_expand(link, envir);
	ft_remove_quotes(link);
	ft_oper(&data, &link);
	return (data);
}

t_token	*ft_searche(t_lexer *lexer)
{
	t_token	*token;

	token = NULL;
	if (lexer->c <= 32)
		ft_skip_space(lexer);
	else if (lexer->c == '|')
		token = ft_token(token_pipe, ft_conv_to_str(lexer->c));
	else if (lexer->c == '>' || lexer->c == '<')
		token = ft_redirection(lexer);
	else
		token = ft_token(token_string, ft_get_str(lexer));
	lexer->i++;
	lexer->c = lexer->input[lexer->i];
	return (token);
}
