/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexxx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:40:46 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/25 12:52:43 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXXX_H
# define FT_LEXXX_H

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
	int		is_heredoc_running;
	int		inputfd;
	int		is_process_running;
}	t_params;

t_params	g_params;

// int	g_exit_error;

t_parser	*ft_lexxx(char *input);
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

char    *get_next_line(int fd);

#endif
