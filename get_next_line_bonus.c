/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:28:48 by romain            #+#    #+#             */
/*   Updated: 2020/11/25 13:01:24 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

static char	*parse_str(char *s, int r)
{
	int		i;
	int		j;
	char	*new;

	if (!s)
		return (NULL);
	i = getlen_n(s, '\n');
	if (!s[i] && r < BUFFER_SIZE)
	{
		free(s);
		return (NULL);
	}
	if (!(new = malloc(sizeof(char) * (getlen_n(s + i, 0) + 1))))
	{
		free(s);
		return (NULL);
	}
	j = -1;
	++i;
	while (s[i])
		new[++j] = s[i++];
	new[++j] = '\0';
	free(s);
	return (new);
}

static char	*get_line_str(char *s)
{
	char	*line;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	i = getlen_n(s, '\n');
	if (!(line = malloc(sizeof(char) * (i + 1))))
	{
		free(s);
		return (NULL);
	}
	i = -1;
	while (s[++i] && s[i] != '\n')
		line[i] = s[i];
	line[i] = '\0';
	return (line);
}

static char	*concatenate_str(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!(s = malloc(sizeof(char) * (getlen_n(s1, 0) + getlen_n(s2, 0) + 1))))
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	i = -1;
	j = 0;
	while (s1 && s1[j])
		s[++i] = s1[j++];
	if (s1)
		free(s1);
	j = 0;
	while (s2 && s2[j])
		s[++i] = s2[j++];
	s[++i] = '\0';
	return (s);
}

static int	read_file(int fd, char **s, char **tmp)
{
	char	read_str[BUFFER_SIZE + 1];
	int		r;

	while ((r = read(fd, read_str, BUFFER_SIZE)) >= 0)
	{
		read_str[r] = '\0';
		if (!(*tmp = concatenate_str(*tmp, read_str)))
			return (-1);
		if (is_line(read_str) || r < BUFFER_SIZE)
		{
			if (!(*s = get_line_str(*tmp)))
			{
				free(*tmp);
				return (-1);
			}
			*tmp = parse_str(*tmp, r);
			return (r < BUFFER_SIZE && (r == 0 || read_str[r - 1] != '\n')
					&& getlen_n(*tmp, 0) == 0 ? 0 : 1);
		}
	}
	return (r);
}

int			get_next_line(int fd, char **s)
{
	static t_file	files[256] = {{NULL, -1}};
	int				r;
	t_file			*tmp;

	if (files[0].str == NULL && files[0].fd == -1)
		fill_struct((t_file *)files);
	tmp = get_file((t_file *)files, fd);
	if (BUFFER_SIZE < 1 || fd < 0 || !s || !tmp)
		return (-1);
	if (is_line(tmp->str))
	{
		if (!(*s = get_line_str(tmp->str)))
		{
			free(tmp->str);
			return (-1);
		}
		tmp->str = parse_str(tmp->str, BUFFER_SIZE);
		return (1);
	}
	if ((r = read_file(fd, s, &tmp->str)) < 1)
		if (tmp->str)
			free(tmp->str);
	return (r);
}
