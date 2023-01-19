
 #include "../../minishell.h"

int	herdoc(t_parser *data)
{
    char	*line;
    int     fd;
    // char    *tmp;

    fd = open("/tmp/herdoc.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    while (data->redi)
    {
        while(1)
        {
            line = readline("> ");
            if (ft_strcmp(line, data->redi->fname) == 0)
                break ;
            write(fd, line, ft_strlen(line));
            write(fd, "\n", 1);
            free(line);
        }
        data->redi = data->redi->next;
    }
    //close(fd);
    return (fd);
}

// int last_herdo(t_parser *data)
// {
//     char	*line;
//     int     fd;
//     char    *tmp;

//     fd = open("/tmp/herdoc.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
//     while (data->redi)
//     {
//         while(1)
//         {
//             line = readline("> ");
//             if (ft_strcmp(line, data->redi->fname) == 0)
//                 break ;
//                 tmo
//             write(fd, line, ft_strlen(line));
//             write(fd, "\n", 1);
//             free(line);
//         }
//     }
// }
