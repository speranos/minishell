#include "../../minishell.h"

// void new_proce(t_parser *data, t_pip *pip)
// {
// 	pip->p_id[pip->i] = fork();
// 	if(pip->p_id[pip->i] == 0)
// 	{
// 		dup2(pip->p_fd[0], 0);
// 		dup2(pip->p_fd[1], 1);
// 		if(data->args[0] && execve(set_path(env, data->args[0]), \
// 		data->args, pip->env) == -1)
// 			exit(1);
// 		exit (0);
// 	}
// }

