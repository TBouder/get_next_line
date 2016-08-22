/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:59:39 by tbouder           #+#    #+#             */
/*   Updated: 2016/08/23 00:12:35 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_return_value(t_gnl gnl, char **line)
{
	if (gnl.i == -1)
		return (-1);
	else if ((ft_strequ(gnl.line, "\n\0") || *line[0] == '\0'
		|| gnl.line[ft_strlen(gnl.line) - 1] == '\0') && gnl.is_ln == 0)
		return (0);
	else
		return (1);
}

static void		ft_buffer_manip(t_gnl *gnl)
{
	gnl->is_ln = ft_strlen(gnl->str);
	gnl->l_len = ft_linelen(gnl->str, 0);
	gnl->line = ft_strsub(gnl->str, 0, gnl->l_len);
	gnl->tmp = ft_strsub(gnl->str, gnl->l_len + 1,
		ft_strlen(&gnl->str[gnl->l_len]));
	ft_strdel(&gnl->str);
	gnl->str = ft_strinit(gnl->tmp);
	ft_strdel(&gnl->tmp);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl	gnl;

	if (line == NULL || fd == -1)
		return (-1);
	if (!gnl.str)
	{
		gnl.buff = ft_strnew(BUFF_SIZE);
		gnl.str = ft_strnew(0);
		while ((gnl.i = read(fd, gnl.buff, BUFF_SIZE)) && gnl.buff[0] != '\0')
		{
			gnl.tmp = ft_strinit(gnl.str);
			ft_strdel(&gnl.str);
			gnl.str = ft_strnjoin(gnl.tmp, gnl.buff, ft_strlen(gnl.tmp), gnl.i);
			ft_strdel(&gnl.tmp);
			if (ft_isstrstr(gnl.buff, "\n"))
				break ;
		}
		ft_strdel(&gnl.tmp);
	}
	ft_buffer_manip(&gnl);
	*line = ft_strinit(gnl.line);
	if (ft_strlen(gnl.str) == 0)
		ft_strdel(&gnl.str);
	return (ft_return_value(gnl, line));
}
