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

#define BUFF_SIZE 1000
#define FILE "one"

t_list	*searchlist(t_list **list, int fd)
{
	t_list *tmp;

	tmp = *list;
	while (tmp != NULL)
	{
		if ((int)(tmp->content_size) == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{	
		tmp = ft_lstnew(NULL, 0);
		tmp->content_size = fd;
		ft_lstadd(&(*list), tmp);
	}
	return (tmp);
}

char	*find_line(t_list *file)
{
	char	*str;
	void	*ptr_buf;
	int		len;
	int		ost;

	ptr_buf = file->content;
	ptr_buf = ft_strchr(file->content, '\n');
	len = ptr_buf - file->content;
	str = ft_strsub(file->content, 0, len);
	ptr_buf = file->content;
	ost = ft_strlen(&(file->content)[len]);
	file->content = ft_strsub(file->content, len + 1, ost);
	free(ptr_buf);
	printf("str = %s\n", str);
	// printf("buf = %s\n", file->content);
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
	if (file->content != NULL)
		tmp = ft_strchr(file->content, '\n');
	if (tmp)
		while (!ft_strchr(tmp, '\n') && read(fd, tmp, BUFF_SIZE) > 0)
		{
			buf_tmp = file->content;
			if (file->content == NULL)
			{
				buf = ft_strsub(tmp, 0, ft_strlen(buf));
				file->content = buf;
			}
			file->content = ft_strjoin(file->content, tmp);
			free(buf_tmp);
		}
	find_line(file);

	*line = buf;
		

	return (1);
}

int main()
{
	int fp;
	char *line;
	// char b;
	fp = open(FILE, O_RDONLY);
	get_next_line(fp, &line);
	get_next_line(fp, &line);
	// {
		// printf("line = %s\n", line);
	// }
	// while (read(0, &b, 1))
	// {
	// 	get_next_line(fp, &line);
	// 	printf("line = %s\n", line);
	// }

	return (0);
}



