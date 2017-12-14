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

#define BUFF_SIZE 500
#define FILE "HEAD"

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

int		find_line(t_list *file, char **line)
{
	// char	*str;
	void	*ptr_buf;
	int		len;
	int		ost;

	len = 0;
	if (ft_strlen(file->content) == 0)
		return (0);
	ptr_buf = file->content;
	ptr_buf = ft_strchr(file->content, '\n');
	if (ptr_buf == NULL)
	{
		*line = ft_strdup(file->content);
		ft_bzero(file->content, ft_strlen(file->content));
		return (1);
	}
	len = ptr_buf - file->content;

	*line = ft_strsub(file->content, 0, len);
	ptr_buf = file->content;
	ost = ft_strlen(&(file->content)[len]);
	file->content = ft_strsub(file->content, len + 1, ost);
	free(ptr_buf);	
	return (1);
}

void	strok_net(t_list **file, char *tmp)
{
	char	*buf;

	buf = NULL;
	if ((*file)->content == NULL)
	{
		buf = ft_strsub(tmp, 0, ft_strlen(tmp));
		(*file)->content = buf;
	}
	else
	{
		buf = (*file)->content;
		(*file)->content = ft_strjoin((*file)->content, tmp);
		free(buf);
	}	
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*file;
	char			*buf;
	char			*tmp;
	int				i;

	i = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	tmp = ft_strnew(BUFF_SIZE);
	buf = NULL;
	file = searchlist(&file, fd);
	if (file->content != NULL)
		buf = ft_strchr(file->content, '\n');
	while (!(ft_strchr(tmp, '\n')) && (i = read(fd, tmp, BUFF_SIZE)) > 0)
		strok_net(&file, tmp);
	if (i < 0)
		return (-1);
	if (ft_strlen(file->content) == 0)
		return (0);
	if (find_line(file, &(*line)) == 0 && i == 0)
		return (0);
	return (1);
}

int main()
{
	int fp;
	char *line;
	fp = open(FILE, O_RDONLY);
	printf("fp %d\n", fp);
	while (get_next_line(0, &line))
		printf("line %s\n", line);


	// get_next_line(fp, &line);
	// printf("line %s\n", line);
	// get_next_line(fp, &line);
	// printf("line %s\n", line);
	// get_next_line(fp, &line);
	// while (read(0, &b, 1))
	// {
	// 	get_next_line(fp, &line);
	// 	printf("line = %s\n", line);
	// }

	return (0);
}



