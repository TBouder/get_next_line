/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:59:39 by tbouder           #+#    #+#             */
/*   Updated: 2016/07/28 19:01:54 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_return_value(t_gnl gnl, char **line)
{
	if (gnl.i == -1)
		return (-1);
	else if ((ft_strequ(gnl.line, "\n\0") || *line[0] == '\0'
		|| gnl.line[ft_strlen(gnl.line) - 1] == '\0') && gnl.is_ln == 0)
		return (0);
	else
		return (1);
}

int		get_next_line(int const fd, char **line)
{
	static t_gnl	gnl;

	if (line == NULL || fd == -1)
		return (-1);
	gnl.list = NULL;
	gnl.buffer = ft_strnew(BUFF_SIZE);
	!gnl.str ? gnl.str = ft_strnew(0) : 0;
	while ((gnl.i = read(fd, gnl.buffer, BUFF_SIZE)) && gnl.buffer[0] != '\0')
	{
		gnl.tmp = ft_strinit(gnl.str);
		ft_strdel(&gnl.str);
		gnl.str = ft_strnjoin(gnl.tmp, gnl.buffer, ft_strlen(gnl.tmp), gnl.i);
		ft_strdel(&gnl.tmp);
		if (ft_isstrstr(gnl.buffer, "\n"))
			break ;
	}
	gnl.is_ln = ft_strlen(gnl.str);
	gnl.l_len = ft_linelen(gnl.str, 0);
	gnl.line = ft_strsub(gnl.str, 0, gnl.l_len);
	gnl.tmp = ft_strsub(gnl.str, gnl.l_len + 1, ft_strlen(&gnl.str[gnl.l_len]));
	ft_strdel(&gnl.str);
	gnl.str = ft_strinit(gnl.tmp);
	ft_strdel(&gnl.tmp);
	*line = ft_strinit(gnl.line);
	return (ft_return_value(gnl, line));
}
