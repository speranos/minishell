/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:42:19 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/19 21:42:21 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

void	ft_add_to_link(t_parser **data, t_token **link, t_parser *tmp);
void	ft_add_red(t_parser **tmp, t_token *link);
void	ft_add_str(t_parser **tmp, t_token *link);
void	ft_init_data(t_parser **tmp, t_token **link);
int		ft_arg_len(t_token *link);
void	ft_remove_quotes(t_token *link);
void	ft_free_redi(t_redi *redi);
void	ft_free_parser(t_parser *data);
void	ft_print(t_parser *data);
void	ft_add_env(t_parser *data, char **env);
void	ft_oper(t_parser **data, t_token **link);
void	ft_quote_to_skip(t_token *link, char c, char *str);
void	ft_mv_to_next(t_token *link_tmp, t_token **link, t_parser **data);

#endif
