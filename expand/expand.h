#ifndef EXPAND_H
#define EXPAND_H

void	ft_expand(t_token *link);
void	ft_check(t_token *link);
void	ft_single(t_token *link);
void	ft_dollar(t_token *link);
int		ft_alpnum(char c);
void	ft_update_ex(t_token *link, int tmp);
int		ft_len(char *str);
void	ft_link_update(t_token *link, char *str, int index, int def);
void	ft_to_fin_str(t_token *link, char *str, char *fin_str, int index, int def);

#endif