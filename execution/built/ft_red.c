
 #include "../../minishell.h"

int	ft_redirection_in_out(t_parser *data)
{
	int fdin;
    int fdout;

	
	while (data->redi)
	{
		//input 
		if(data->redi->type == 0)
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
		else if(data->redi->type == 1)
		{
			printf("type : %d\n", data->redi->type);
			fdout = open(data->redi->fname, O_WRONLY|O_CREAT|O_TRUNC, 0644);
			if (access(data->redi->fname, R_OK))
				printf("Error : Permission denied\n");
			dup2(fdout, 1);
			close(fdout);
		}
		else if (data->redi->type == 2)
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