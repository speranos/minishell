/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:40:09 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/26 10:54:55 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

void	ft_expand(t_token *link);
void	ft_check(t_token *link);
void	ft_single(t_token *link);
void	ft_dollar(t_token *link);
int		ft_alphanum(char c);
void	ft_update_ex(t_token *link, int tmp);
int		ft_len(char *str);
void	ft_link_update(t_token *link, char *str, int index, int def);
char	*ft_to_fin_str(t_token *link, char *str, int index, int def);
int		ft_alpha(t_token *link);
void	ft_rm_num(t_token *link);
void	ft_rm_dollar(t_token *link);
void	ft_quest_mark(t_token *link);
char	*itoa(int num);
int		ft_num_len(int num);
int		ft_fin_len(t_token *link, char *str, int def);
void	ft_num_to_finstr(t_token *link, int len, int tmp);

#endif
