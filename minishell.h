/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:02:50 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/26 23:12:52 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_envir
{
	char			*line_env;
	char			*name;
	char			*value;
	struct s_envir	*next;
}t_envir;

typedef struct lexer
{
	int		i;
	char	c;
	int		len;
	char	*input;
	int		quotes;
}	t_lexer;

typedef struct token
{
	enum
	{
		token_string,
		token_pipe,
		token_red_input,
		token_red_output,
		token_app_input,
		token_app_error,
	}	e_type;
	char			*str;
	struct token	*next;
	int				i;
	int				len;
	int				index;
}	t_token;

typedef struct redi
{
	enum
	{
		red_input,
		red_output,
		app_input,
		app_error
	}	e_type;
	char		*fname;
	struct redi	*next;
}	t_redi;

typedef struct parser
{
	char			**args;
	t_redi			*redi;
	int				her_doc;
	int				herdoc_fd;
	pid_t			process_id;
	int				exit_status;
	struct parser	*next;
}	t_parser;

typedef struct s_params
{
	int		ret;
	int		herdoc_dead;
	int		is_heredoc_running;
	int		inputfd;
	int		is_process_running;
}	t_params;

t_params	g_params;

void		ft_intro(void);
void		init_env(t_envir **env, t_envir **exp);
void		ft_args_check(int ac, char **env, t_envir **envir, t_envir **exp);
void		ft_add_to_link(t_parser **data, t_token **link, t_parser *tmp);
void		ft_add_red(t_parser **tmp, t_token *link);
void		ft_add_str(t_parser **tmp, t_token *link);
void		ft_init_data(t_parser **tmp, t_token **link);
int			ft_arg_len(t_token *link);
void		ft_remove_quotes(t_token *link);
void		ft_free_redi(t_redi *redi);
void		ft_free_parser(t_parser *data);
void		ft_print(t_parser *data);
void		ft_add_env(t_parser *data, char **env);
void		ft_oper(t_parser **data, t_token **link);
void		ft_quote_to_skip(t_token *link, char c, char *str);
void		ft_mv_to_next(t_token *link_tmp, t_token **link, t_parser **data);
void		ft_redi_add_link(t_parser **tmp, t_redi *red_tmp);

t_parser	*ft_lexxx(char *input, t_envir *envir);
t_token		*ft_token(int type, char *str);
char		*ft_conv_to_str(char c);
void		ft_skip_space(t_lexer *lexer);
int			ft_check_sym(char c, t_lexer *lexer);
char		*ft_get_str(t_lexer *lexer);
t_token		*ft_searche(t_lexer *lexer);
void		ft_syntax_error(void);
void		ft_quotes_skip(t_lexer *lexer);
t_token		*ft_redirection(t_lexer *lexer);
t_token		*ft_red_output(t_lexer *lexer);
t_token		*ft_app_error(t_lexer *lexer);
t_token		*ft_red_input(t_lexer *lexer);
t_token		*ft_app_input(t_lexer *lexer);
void		ft_ignore_spaces(t_lexer *lexer);
void		ft_single_quotes(t_lexer *lexer);
void		ft_init(t_token *link);
char		*get_next_line(int fd);

void		ft_expand(t_token *link, t_envir *envir);
void		ft_check(t_token *link, t_envir *envir);
void		ft_single(t_token *link);
void		ft_dollar(t_token *link, t_envir *envir);
int			ft_alphanum(char c);
void		ft_update_ex(t_token *link, int tmp, t_envir *envir);
int			ft_len(char *str);
void		ft_link_update(t_token *link, char *str, int index, int def);
char		*ft_to_fin_str(t_token *link, char *str, int index, int def);
int			ft_alpha(t_token *link, t_envir *envir);
void		ft_rm_num(t_token *link);
void		ft_rm_dollar(t_token *link, t_envir *envir);
void		ft_quest_mark(t_token *link);
char		*itoa(int num);
int			ft_num_len(int num);
int			ft_fin_len(t_token *link, char *str, int def);
void		ft_num_to_finstr(t_token *link, int len, int tmp);

int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
t_envir		*ft_lstnew(char *line);
int			ft_lstsize(t_envir *list);
void		ft_add_front(t_envir *var, t_envir *new);
void		ft_add_ba(t_envir **stack, t_envir *new);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
void		delete_node(t_envir **env, char *name);
char		*ft_strdup(const char *s1);
int			ft_check_alpha(char *word);
int			is_number(char *str);
int			is_valid(char *str);
char		*ft_strndup(const char *s1, size_t n);
int			ft_atoi(const char *str);

int			ft_syntax_check(t_token *link);
int			ft_after_red(t_token *link);
int			ft_after_pipe(t_token *link);

//built
char		*ft_pwd(t_envir *env);
int			ft_echo(char **arg, int fd);
int			ft_cd(char *argv, t_envir **env, t_envir **exp);
int			ft_exit(char **arg, int argc, int fd);
int			ft_unset(t_envir **envir, t_envir **exp, char **arg, int fd);
void		ft_copy_env(char **env, t_envir **envir);
int			ft_export(t_envir **exp, t_envir **env, t_parser *data, int fd);
void		sort_export(t_envir *exp);
int			ft_env_printf(t_envir *env, int fd);
void		ft_exp_printf(t_envir *exp, int fd);
void		init_env(t_envir **env, t_envir **exp);
int			ft_count_arg(char **arg);
int			ft_sear_env(t_envir **envir, char *arg);
void		ft_built(t_envir **envir, t_envir **exp, t_parser *tmp, int fd);
int			is_built(t_parser *tmp);
int			ft_error(char *str, char *arg, char *str2, int exit);
int			is_valid(char *str);

//pipe
char		**ft_split(const char *s, char c);
char		*set_path(t_envir **env, char *cmd, int i);
int			size_list(t_parser *list);
void		execution_utils(t_envir **envir, t_envir **exp, \
t_parser *data, int *temp_fd);
void		mul_pip(t_envir **envir, t_envir **exp, \
t_parser *data, int *temp_fd);
int			ft_redirection_built_out(t_parser *data);
int			ft_redirection_in_out(t_parser *data);
void		red_0(t_parser *data, int fdin);

int			one_node(t_envir **env, t_envir **exp, t_parser *data);
void		ft_execution(t_envir **envir, t_envir **exp, t_parser *data);
char		**set_env(t_envir *env);
int			herdoc(t_parser *data);
void		check_herdox(t_parser *data);
void		exit_status(char *str);
void		free_double(char **str);
char		*get_env(char *var, t_envir *env);

#endif
