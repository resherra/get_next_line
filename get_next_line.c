/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:22:17 by recherra          #+#    #+#             */
/*   Updated: 2024/02/03 21:33:14 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (!s1)
		return (strdup(s2));
	len = strlen(s1) + strlen(s2);
	res = calloc(len + 1, sizeof(char));
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
    char *next_line = NULL;
    int readed = BUFFER_SIZE;
    int truncated = -1;
    char *tmp = NULL ;

    if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0, 0)) < 0)
        return NULL;

    while(readed == BUFFER_SIZE && truncated == -1)
    {
        readed = read(fd, buffer, BUFFER_SIZE);
        buffer[readed] = 0 ;
        line = ft_strjoin(line, buffer);
        truncated = ft_trunc(line);
    }
    if (truncated < 0)
    {
        if(line != NULL)
            tmp =strdup(line);
        line = NULL;
        return tmp;
    }
    else
    {
        next_line = calloc(truncated + 2, sizeof (char));
        strlcpy(next_line, line, truncated + 2);
        line = strdup(line + truncated + 1);
    }
    
    return next_line;
}