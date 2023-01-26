/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:55:25 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/26 10:55:26 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_redirection(t_lexer *lexer)
{
	t_token	*token;

	token = NULL;
	if (lexer->c == '<')
	{
		if (lexer->input[lexer->i + 1] == '<')
			token = ft_app_input(lexer);
		else
			token = ft_red_input(lexer);
	}
	else if (lexer->c == '>')
	{
		if (lexer->input[lexer->i + 1] == '>')
			token = ft_app_error(lexer);
		else
			token = ft_red_output(lexer);
	}
	return (token);
}

void	ft_ignore_spaces(t_lexer *lexer)
{
	while (lexer->input[lexer->i] && lexer->input[lexer->i] <= 32)
		lexer->i++;
}
