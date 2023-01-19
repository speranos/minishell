/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:32:59 by abihe             #+#    #+#             */
/*   Updated: 2023/01/19 18:50:16 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include<unistd.h>
#include <string.h>
#include <fcntl.h>
#include "../parser/parser.h"

typedef struct s_envir
{
	char			*line_env;
	char			*name;
	char			*value;
	struct s_envir	*next; 
}   t_envir;

typedef struct s_pip
{
	char	**path;
	char	*str;
	char	**env;
	char	*in_fi;
	char	*out_fi;
	int		nb_pip;
	int		i;
	int		*p_id;
	int		*p_fd;
	int		**fd;
	int		pi[2];
	
}	t_pip;


//lib
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
t_envir	*ft_lstnew(char *line);
int		ft_lstsize(t_envir *list);
void	ft_add_front(t_envir *var, t_envir *new);
void	ft_add_ba(t_envir **stack, t_envir *new);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void    delete_node(t_envir **env, char *name);
char	*ft_strdup(const char *s1);
int		ft_check_alpha(char *word);
int		is_number(char *str);
int		is_valid(char *str);
char    *ft_strndup(const char *s1, size_t n);

//built
char	*ft_pwd(void);
char	*ft_echo(char **arg, int fd);
void	ft_cd(char *argv, t_envir **env, t_envir **exp);
void	ft_exit(char **arg, int argc, int fd);
void	ft_unset(t_envir **envir, t_envir **exp, char **arg, int fd);
void	ft_copy_env(char **env, t_envir **envir);
void	ft_export(t_envir **exp, t_envir **env, t_parser *data , int fd);
void	sort_export(t_envir *exp);
void	ft_env_printf(t_envir *env, int fd);
void	ft_exp_printf(t_envir *exp, int fd);
void	init_env(t_envir **env, t_envir **exp);
int		ft_count_arg(char **arg);
int		ft_sear_env(t_envir **envir,char *arg);
void    ft_built(t_envir **envir, t_envir **exp, t_parser *tmp, int fd);
int		is_built(t_parser *tmp);

//pipe
char	**ft_split(const char *s, char c);
t_pip	*ft_fil_pip(t_pip *pip, t_parser *data);
char	*set_path(t_envir **env, char *cmd);
int		size_list(t_parser *list);
void    close_pip(t_pip *pip);
// void 	new_proce(t_parser *data, t_pip *pip, t_envir **env);
void	uno_node(t_envir **env, t_envir **exp, t_parser *data, t_pip **pip);
t_pip	*ft_exec(t_envir **exp, t_envir **env, t_parser *data);
int	ft_redirection_in_out(t_parser *data);


int		one_node(t_envir **env, t_envir **exp, t_parser *data);
void	ft_execution(t_envir **envir, t_envir **exp, t_parser *data);
char	**set_env(t_envir *env);
int		herdoc(t_parser *data);

# endif