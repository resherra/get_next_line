/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:22:17 by recherra          #+#    #+#             */
/*   Updated: 2024/02/05 17:24:00 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
    if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, buffer, 0)) < 0)
    {
        free(line);
        line = NULL;
        return NULL;
    }
    while (readed == BUFFER_SIZE && truncated == -1)
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
        if (line)
        {
            tmp = ft_strdup(line);
        }
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