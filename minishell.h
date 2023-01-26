/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:02:50 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/26 11:02:52 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include "lexer/ft_lexxx.h"
# include "syntax_check/ft_syntax.h"
# include "parser/parser.h"
# include "expand/expand.h"
# include <signal.h>
# include "execution/exec.h"

void	ft_intro(void);
void	init_env(t_envir **env, t_envir **exp);
void	ft_args_check(int ac, char **env, t_envir **envir, t_envir **exp);

#endif
