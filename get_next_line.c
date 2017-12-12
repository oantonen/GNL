/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:16:45 by oantonen          #+#    #+#             */
/*   Updated: 2017/12/11 19:55:13 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include "libft/includes/libft.h"

#define BUFF_SIZE 30
#define FILE "head"

t_list	*searchlist(t_list **list, int fd)
{
	t_list *tmp = *list;

	while (tmp != NULL)
	{
		if (tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (*list == NULL)
	{
		*list = ft_lstnew(NULL, 0);
		°list = ft_lstadd(list);
		*list->content_size = fd;
	}
	if (tmp == NULL)

}

char	*find_line(char *buf)
{

	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*file;
	char			*buf;
	char			*tmp = NULL;
	char			*buf_tmp;

	if (fd < 0 || BUFF_SIZE == 0)
		return (0);
	tmp = ft_strnew(BUFF_SIZE);
	buf = ft_strnew(1);
	file = searchlist(&file, fd);
	while (!ft_strchr(tmp, '\n') && read(fd, tmp, BUFF_SIZE) > 0)
	{
		buf_tmp = buf;
		buf = ft_strjoin(buf, tmp);
		// free(buf_tmp);
	}

	*line = find_line(buf);
		

	return (1);
}

int main()
{
	int fp;
	char *line;
	// char b;
	fp = open(FILE, O_RDONLY);
	while ((get_next_line(fp, &line)) == 1)
	{
		printf("line = %s\n", line);
	}
	// while (read(0, &b, 1))
	// {
	// 	get_next_line(fp, &line);
	// 	printf("line = %s\n", line);
	// }

	return (0);
}



