/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redi_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:16:48 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/26 15:17:04 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
