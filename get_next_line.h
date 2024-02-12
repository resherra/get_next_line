/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:20:30 by recherra          #+#    #+#             */
/*   Updated: 2024/02/12 15:17:30 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char	*buffer;
	char	*next_line;
	char	*tmp;
	int		readed;
	int		truncated;

}			t_list;

char		*get_next_line(int fd);
char		*ft_strjoin(char *line, char *buffer);
char		*ft_strdup(char *str);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
int			ft_trunc(char *str);

#endif
