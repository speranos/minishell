#include "../../minishell.h"
#include <string.h>

int ft_equal(char *str)
{
	int i;
	i = 0;
	while(str[i])
	{
		if(str[i] == '=')
			return (0);
		i++;
	}
	return(1);
}

void	ft_exp_printf(t_envir *exp, int fd)
{
	while(exp)
	{
		if(ft_equal(exp->line_env))
		{
			ft_putstr_fd("declare -x ", fd);
			ft_putstr_fd(exp->line_env, fd);
			ft_putstr_fd("\n", fd);
		}
			// printf("declare -x %s\n",exp->name);
		else
		{
			ft_putstr_fd("declare -x ", fd);
			ft_putstr_fd(exp->name, fd);
			ft_putstr_fd("=\"", fd);
			ft_putstr_fd(exp->value, fd);
			ft_putstr_fd("\"\n", fd);
		}
			// printf("declare -x %s=\"%s\"\n", exp->name,exp->value);
		exp = exp->next;
	}
}

int    ft_count_arg(char **arg)
{
	int i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

void	ft_swap_data(t_envir *exp)
{
	char *tmp1;

	tmp1 = exp->line_env;
	exp->line_env = exp->next->line_env;
	exp->next->line_env = tmp1;

	tmp1 = exp->name;
	exp->name = exp->next->name;
	exp->next->name = tmp1;

	tmp1 = exp->value;
	exp->value = exp->next->value;
	exp->next->value = tmp1;
}

void	sort_export(t_envir *exp)
{
	int		i;
	int		size;
	t_envir	*exp_tmp;

	i = 0;
	size = ft_lstsize(exp);
	exp_tmp = exp;
	while (i < size)
	{
		exp = exp_tmp;
		while (exp->next)
		{
			if (ft_strcmp(exp->line_env, exp->next->line_env) > 0)
				ft_swap_data(exp);
			exp = exp->next;
		}
		i++;
	}
}

int	is_valid(char *str)
{
	int i;

	i = 0;
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_')
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_export(t_envir **exp, t_envir **env, t_parser *data, int fd)
{
	int si;
	int i;
	int size;
	char *name;

	i = 1;
	si = ft_count_arg(data->args);
	if (si < 2)
	{
		sort_export(*exp);
		ft_exp_printf(*exp, fd);
	}
	else
	{
		while (i < si)
		{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
			if(data->args[i] )
			{
				if (!ft_sear_env(exp, data->args[i]))
				{
					if (ft_strchr(data->args[i], '=') != NULL)
					{
						size = ft_strlen(ft_strchr(data->args[i], '='));
						name = ft_substr(data->args[i], 0, ft_strlen(data->args[i]) - size);
						delete_node(exp, name);
						delete_node(env, name);
						ft_add_ba(exp, ft_lstnew(data->args[i]));
						ft_add_ba(env, ft_lstnew(data->args[i]));
					}
				}
				else if(ft_strchr(data->args[i], '='))
				{
					ft_add_ba(env, ft_lstnew(data->args[i]));
					ft_add_ba(exp, ft_lstnew(data->args[i]));
				}
				else
					ft_add_ba(exp, ft_lstnew(data->args[i]));
			}
			else
			{
				ft_putstr_fd("minishell: export: `", fd);
				ft_putstr_fd(data->args[i], fd);
				ft_putstr_fd("': not a valid identifier\n", fd);
			}
			i++;
		}
	}
}