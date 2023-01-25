#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "minishell.h"

char    *ft_join(char *s, char c)
{
    int    i;
    char    *str;

    i = 0;
    if (c == '\n')
        return (s);
    while (s[i])
        i++;
    str = malloc(sizeof(char) * (i + 2));
    i = 0;
    while (s[i])
    {
        str[i] = s[i];
        i++;
    }
    str[i] = c;
    str[i + 1] = '\0';
    free(s);
    return(str);
}

char    *get_next_line(int fd)
{
    char    *str;
    char    buff;
    int        r;

    r = read(fd, &buff, 1);
    str = malloc(1);
    str[0] = '\0';
    while (r > 0)
    {
        str = ft_join(str, buff);
        if (buff == '\n')
            break ;
        r= read(fd, &buff, 1);
    }
    if ((str[0] == '\0' && r == 0) || r < 0)
    {
        free (str);
        return (NULL);
    }
    return (str);
}
