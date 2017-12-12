/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:19:34 by oantonen          #+#    #+#             */
/*   Updated: 2017/12/11 19:50:56 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// #define BUFF_SIZE 32

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_string
{
	int n;
	char str[];
}			t_str;

int		get_next_line(const int fd, char **line);
// char	*ft_strncpy(char *dst, const char *src, size_t len);
// void	*ft_memset(void *b, int c, size_t len);
// char	*ft_strnew(size_t size);
// char	*ft_strsub(char const *s, unsigned int start, size_t len);
// char	*ft_strcpy(char *dst, const char *src);
// char	*ft_strchr(const char *s, int c);
// size_t	ft_strlen(const char *s);
// char	*ft_strjoin(char const *s1, char const *s2);


#endif