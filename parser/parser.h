#ifndef	PARSER_H
#define	PARSER_H

typedef struct redi
{
	enum
	{
		red_input, //<
		red_output, //>
		app_input, //<<
		app_error //>>
	}	type;
	char	*fname;
	struct redi *next;
}	t_redi;

typedef struct parser
{
	char	**args;
	t_redi	*redi;
	struct parser *next;
}	t_parser;

void	ft_rev(t_token *link);
void	ft_add_to_link(t_parser **data, t_token **link, t_parser *tmp);
void	ft_add_red(t_parser **tmp, t_token *link);
void	ft_add_str(t_parser **tmp, t_token *link);
void	ft_init_data(t_parser **tmp, t_token **link);
int		ft_arg_len(t_token *link);
void	ft_remove_quotes(t_token *link);
void	ft_free_redi(t_redi *redi);
void	ft_free_parser(t_parser *data);
void	ft_print(t_parser *data);


#endif