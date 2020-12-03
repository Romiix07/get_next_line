/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:38:49 by romain            #+#    #+#             */
/*   Updated: 2020/11/24 17:08:25 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line_bonus.h"

int		is_line(char *s)
{
	while (s && *s)
	{
		if (*s == '\n')
			return (1);
		++s;
	}
	return (0);
}

int		getlen_n(const char *s, char n)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] && s[i] != n)
		++i;
	return (i);
}

void	fill_struct(t_file *files)
{
	int		i;

	i = -1;
	while (++i < 256)
	{
		files[i].str = NULL;
		files[i].fd = -1;
	}
}

t_file	*get_file(t_file *files, int fd)
{
	int		i;

	i = 0;
	while (fd != -1 && i < 256 && files[i].fd != -1 && files[i].fd != fd)
		++i;
	if (fd == -1 || i == 256)
		return (NULL);
	files[i].fd = fd;
	return (&files[i]);
}
