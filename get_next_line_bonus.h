/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:49:40 by romain            #+#    #+#             */
/*   Updated: 2020/11/24 17:08:10 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

typedef struct	s_file {
	char	*str;
	int		fd;
}				t_file;

int				get_next_line(int fd, char **s);
int				getlen_n(const char *s, char n);
int				is_line(char *s);
void			fill_struct(t_file *files);
t_file			*get_file(t_file *files, int fd);

#endif
