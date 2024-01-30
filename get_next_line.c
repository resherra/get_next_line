/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:22:17 by recherra          #+#    #+#             */
/*   Updated: 2024/01/30 20:13:32 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int checker(char *str)
{
    int i;

    i = 0;

    while (str[i])
    {
        if (str[i] == '\n')
            return i;
        i++;
    }

    return -1;
}

char *reader()
{



}


char *get_next_line(int fd)
{
    char *str;
    int reader;
    int line_check;

    str = calloc(BUFFER_SIZE + 1, sizeof (char));
    reader = read(fd, str, BUFFER_SIZE);
    

    
    while 
    line_check = checker(str);
     (!line_check)
    {

    }
    
    
    printf("inside '%s'\n", str);
    return str;
}