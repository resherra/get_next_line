/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:22:17 by recherra          #+#    #+#             */
/*   Updated: 2024/01/31 20:26:15 by recherra         ###   ########.fr       */
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
	if (!s1 || !s2)
		return (NULL);
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

char *get_next_line(int fd)
{
    char *str;
    size_t reader;
    reader = 0;
    char *new;
    int i = 0;

    str = calloc(BUFFER_SIZE + 1, sizeof (char));
    while (((reader = read(fd, str, BUFFER_SIZE)) > 0) && !ft_strchr(str, '\n'))
    {
        i++;
        // printf("i: %d\n", i);
        printf("str '%s'\n", str);
    }
    new = calloc(BUFFER_SIZE, sizeof(char));
    if (!new)
        return NULL;
    read(fd, new, BUFFER_SIZE * i);
    printf("new: %s\n", new);
    return str;
}