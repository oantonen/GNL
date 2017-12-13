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
#define FILE "head"

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
	if (ft_strlen(file->content) == 0)
		return (0);
	// printf("strlen %zu\n", ft_strlen(file->content));
	printf("str = %s\n", str);
	// printf("buf = %s\n", file->content);
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*file;
	char			*buf;
	char			*tmp;
	int				i;

	i = 0;
	if (fd < 0 || BUFF_SIZE == 0)
		return (0);
	tmp = ft_strnew(BUFF_SIZE);
	buf = ft_strnew(1);
	file = searchlist(&file, fd);
	// if (file->content != NULL)
	// 	file->content = ft_strchr(btf, '\n');
	while ( (i = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		(file->content == NULL) ? buf = ft_strsub(tmp, 0, ft_strlen(tmp)) : buf;
		(file->content == NULL) ? file->content = buf : buf;
		buf = file->content;
		file->content = ft_strjoin(file->content, tmp);
		free(&buf[0]);
	}
	// find_line(file);
	if ((*line = find_line(file)) == 0 && i <= 0)
		return (0);
	return (1);
}

int main()
{
	int fp;
	char *line;
	// char b;
	fp = open(FILE, O_RDONLY);
	// while (get_next_line(fp, &line))
		// printf("line %s\n", line);
	get_next_line(fp, &line);
	get_next_line(fp, &line);
	// while (read(0, &b, 1))
	// {
	// 	get_next_line(fp, &line);
	// 	printf("line = %s\n", line);
	// }

	return (0);
}



