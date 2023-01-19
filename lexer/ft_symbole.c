/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_symbole.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:41:40 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/19 21:41:42 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_skip_space(t_lexer *lexer)
{
	while (lexer->input[lexer->i] <= 32 && lexer->input[lexer->i])
		lexer->i++;
	lexer->i--;
}

char	*ft_conv_to_str(char c)
{
	char	*ret;

	ret = malloc(sizeof(char) * 2);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}
