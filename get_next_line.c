/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:16:45 by oantonen          #+#    #+#             */
/*   Updated: 2017/12/04 09:53:20 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

// #include <stdlib.h>
// #include <fcntl.h>
// #include <unistd.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *ptr;

	ptr = dst;
	while (len)
	{
		if (!*src)
			break ;
		else
			*ptr++ = *src++;
		len--;
	}
	while (len)
	{
		*ptr++ = '\0';
		len--;
	}
	return (dst);
}

int get_next_line(const int fd, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	if (read(fd, tmp, BUFF_SIZE) == -1)
		return (-1);
	tmp[BUFF_SIZE] = '\0';
	while (*tmp && *tmp++ != '\n')
		len++;
	if (len > BUFF_SIZE)
		read(fd, tmp, BUFF_SIZE);
	*line = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	tmp = tmp - len - 1;
	ft_strncpy(*line, tmp, len);
	return (1);
}

int main()
{
	int fp;
	char *line;

	// line = NULL;

	fp = open(".//test.c", O_RDONLY);
	// line = (char*)malloc(sizeof(char) * 1500);
	get_next_line(fp, &line);
	printf("%s", line);
	// printf("%s\n", &line[0]);
	// printf("%s\n", &line[1]);

	return (0);

}