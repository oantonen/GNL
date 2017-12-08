/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:19:34 by oantonen          #+#    #+#             */
/*   Updated: 2017/12/04 09:55:00 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFF_SIZE 32

typedef struct s_string
{
	int n;
	char str[];
}			t_str;

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


#endif