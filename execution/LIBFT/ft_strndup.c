#include "../../minishell.h"

char    *ft_strndup(const char *s1, size_t n)
{
    size_t        i;
    char        *scpy;

    scpy = (char *) malloc (sizeof(char) * n + 1);
    if (!scpy)
        return (NULL);
    i = 0;
    while (i < n)
    {
        scpy[i] = s1[i];
        i++;
    }
    scpy[i] = '\0';
    return (scpy);
}