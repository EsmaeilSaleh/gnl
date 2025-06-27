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
char *ft_strjoin(char *s1, const char *s2)
{
    char *joined;
    size_t len1;
    size_t len2;
    size_t i;
    size_t j;

    if (!s1 && !s2)
        return (NULL);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    joined = malloc(len1 + len2 + 1);
    if (!joined)
        return (NULL);
    i = 0;
    while (s1 && s1[i])
    {
        joined[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2 && s2[j])
        joined[i++] = s2[j++];
    joined[i] = '\0';
    free(s1);
    return (joined);
}

char *extract_line(char *stash)
{
    size_t i = 0;
    char *line;

    if (!stash || !stash[0])
        return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    line = malloc(i + 1);
    if (!line)
        return (NULL);
    for (size_t j = 0; j < i; j++)
        line[j] = stash[j];
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
    i++;
    new_stash = malloc(ft_strlen(stash + i) + 1);
    if (!new_stash)
        return (NULL);
    while (stash[i])
        new_stash[j++] = stash[i++];
    new_stash[j] = '\0';
    free(stash);
    return (new_stash);
}