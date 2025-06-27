#include <stdlib.h>

size_t ft_strlen(const char *s)
{
    size_t len = 0;

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
    size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s2);
    char *res = malloc(len1 + len2 + 1);
    size_t i = 0, j = 0;

    if (!res)
        return (NULL);
    while (s1 && s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    while (s2 && s2[j])
        res[i++] = s2[j++];
    res[i] = '\0';
    free(s1);
    return (res);
}

char *extract_line(char *stash)
{
    size_t i = 0;
    char *line;

    if (!stash || !stash[0])
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
    size_t i = 0, j = 0;
    char *new_stash;

    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
    {
        free(stash);
        return (NULL);
    }
    new_stash = malloc(ft_strlen(stash + i + 1) + 1);
    if (!new_stash)
        return (NULL);
    i++;
    while (stash[i])
        new_stash[j++] = stash[i++];
    new_stash[j] = '\0';
    free(stash);
    return (new_stash);
}
