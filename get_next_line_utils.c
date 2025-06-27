#include <stdlib.h>

size_t ft_strlen(const char *s)
{
    size_t len;

    len = 0;
    while (s && s[len])
        len++;
    return (len);
}

char *ft_strchr(const char *s, int c)
{
    if (!s)
        return (NULL);
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return (NULL);
}
char *ft_strjoin(char *s1, char *s2)
{
    char *res;
    size_t len1;
    size_t len2;
    size_t i;
    size_t j;

    if (!s2)
        return (s1);
    len1 = s1 ? ft_strlen(s1) : 0;
    len2 = s2 ? ft_strlen(s2) : 0;
    res = malloc(len1 + len2 + 1);
    if (!res)
    {
        if (s1)
            free(s1);
        return (NULL);
    }
    i = 0;
    while (s1 && s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2 && s2[j])
        res[i++] = s2[j++];
    res[i] = '\0';
    if (s1 != res && s1)
        free(s1);
    return (res);
}

char *extract_line(char *stash)
{
    char *line;
    size_t i;

    i = 0;
    if (!stash || stash[0] == '\0')
        return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    line = malloc(i + (stash[i] == '\n') + 1);
    if (!line)
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
    {
        line[i] = stash[i];
        i++;
    }
    if (stash[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

char *update_stash(char *stash)
{
    char *new_stash;
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
    {
        free(stash);
        return (NULL);
    }
    new_stash = malloc(ft_strlen(stash + i + 1) + 1);
    if (!new_stash)
    {
        free(stash);
        return (NULL);
    }
    i++;
    while (stash[i])
        new_stash[j++] = stash[i++];
    new_stash[j] = '\0';
    if (new_stash[0] == '\0')
    {
        free(new_stash);
        return (NULL);
    }
    free(stash);
    return (new_stash);
}
