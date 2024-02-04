/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:22:17 by recherra          #+#    #+#             */
/*   Updated: 2024/02/04 16:43:02 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
size_t	ft_strlen(const char *s1)
{
	int	i;
    if (!s1 || !(*s1))
        return 0;
	i = 0;
	while (s1[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	if (!dstsize)
		return (len);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;
	int		i;

    if (!s1 || !(*s1))
        return NULL;
	i = 0;
	len = ft_strlen(s1);
	str = malloc((len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
    str[len]='\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (s1[j])
	{
		res[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		res[j + i] = s2[i];
		i++;
	}
    res[len]='\0';
	return (res);
}

char *ft_strchr(const char *str, int c)
{
    char *s;

    if (!str)
        return NULL;
    s = (char *)str;
    
    while (*s)
    {
        if (*s == c)
            return s;
        s++;
    }
    
    if (c == '\0')
        return s;
    return NULL;
}

int  ft_trunc(char *str)
{
    int i = 0;

    if (!str)
        return -1;
    while (str[i])
    {
        if (str[i] == '\n')
            return i;
        i++;
    }

    return -1;
}

char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE + 1];
    static char *line;
    char *next_line;
    char *tmp;
    int readed;
    int truncated;

    next_line = NULL;
    readed = BUFFER_SIZE;
    truncated = -1;
    tmp = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0, 0)) < 0)
    {
        free(line);
        line= NULL;
        return NULL;
    }
    while(readed == BUFFER_SIZE && truncated == -1)
    {
        readed = read(fd, buffer, BUFFER_SIZE);
        buffer[readed] = '\0';
        tmp = line;
        line = ft_strjoin(line, buffer);
        free(tmp);
        tmp = NULL;
        truncated = ft_trunc(line);
    }
    if (truncated < 0)
    {
        if (line != NULL)
            tmp = ft_strdup(line);
        free(line);
        line = NULL;
        return tmp;
    }
    else
    {
        next_line = malloc(truncated + 2);
        if (!next_line)
        {
            free(line);
            line = NULL;
            return NULL;
        }
        ft_strlcpy(next_line, line, truncated + 2);
        tmp = line;
        line = ft_strdup(line + truncated + 1);
        free(tmp);
    }
    
    return next_line;
}