/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:42:41 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/26 10:56:24 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SYNTAX_H
# define FT_SYNTAX_H

int	ft_syntax_check(t_token *link);
int	ft_after_red(t_token *link);
int	ft_after_pipe(t_token *link);
#endif
