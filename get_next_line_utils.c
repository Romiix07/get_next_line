/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:38:49 by romain            #+#    #+#             */
/*   Updated: 2020/11/23 21:57:04 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

int	is_line(char *s)
{
	while (s && *s)
	{
		if (*s == '\n')
			return (1);
		++s;
	}
	return (0);
}

int	getlen_n(const char *s, char n)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] && s[i] != n)
		++i;
	return (i);
}
