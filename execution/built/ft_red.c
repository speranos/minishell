
 #include "../../minishell.h"

int	ft_redirection_in_out(t_parser *data)
{
	int fdin;
    int fdout;

	
	while (data->redi)
	{
		//input 
<<<<<<< HEAD
		if(data->redi->e_type == 0)
=======
		if(data->redi->type == 0)
>>>>>>> 6ded913c7dd048de9aa388486f49797f72da67b2
		{
			fdin = open(data->redi->fname, O_RDONLY);
			
			if (fdin < 0)
            {
				printf("Minishell: %s:  No such file or directory\n",data->redi->fname);
                return (-1);
            }
			dup2(fdin, 0);
			close(fdin);
		}
<<<<<<< HEAD
		else if(data->redi->e_type == 1)
		{
			printf("e_type : %d\n", data->redi->e_type);
=======
		else if(data->redi->type == 1)
		{
			printf("type : %d\n", data->redi->type);
>>>>>>> 6ded913c7dd048de9aa388486f49797f72da67b2
			fdout = open(data->redi->fname, O_WRONLY|O_CREAT|O_TRUNC, 0644);
			if (access(data->redi->fname, R_OK))
				printf("Error : Permission denied\n");
			dup2(fdout, 1);
			close(fdout);
		}
<<<<<<< HEAD
		else if (data->redi->e_type == 2)
=======
		else if (data->redi->type == 2)
>>>>>>> 6ded913c7dd048de9aa388486f49797f72da67b2
		{
			int fd = herdoc(data);
			dup2(fd, 0);
			close(fd);
			return (0);
		}
		data->redi = data->redi->next;
	}
        //dup2(fdin, 0);
    return (fdout);
}
