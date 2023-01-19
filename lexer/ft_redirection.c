/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:40:53 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/19 21:40:55 by aoueldma         ###   ########.fr       */
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

t_token	*ft_app_input(t_lexer *lexer)
{
	char	*ret;

	lexer->i += 2;
	ft_ignore_spaces(lexer);
	ret = ft_get_str(lexer);
	return (ft_token(token_app_input, ret));
}

t_token	*ft_red_input(t_lexer *lexer)
{
	char	*ret;

	lexer->i++;
	ft_ignore_spaces(lexer);
	ret = ft_get_str(lexer);
	return (ft_token(token_red_input, ret));
}

t_token	*ft_app_error(t_lexer *lexer)
{
	char	*ret;

	lexer->i += 2;
	ft_ignore_spaces(lexer);
	ret = ft_get_str(lexer);
	return (ft_token(token_app_error, ret));
}

t_token	*ft_red_output(t_lexer *lexer)
{
	char	*ret;

	lexer->i++;
	ft_ignore_spaces(lexer);
	ret = ft_get_str(lexer);
	return (ft_token(token_red_output, ret));
}

void	ft_ignore_spaces(t_lexer *lexer)
{
	while (lexer->input[lexer->i] && lexer->input[lexer->i] <= 32)
		lexer->i++;
}
