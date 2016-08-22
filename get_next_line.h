/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:59:39 by tbouder           #+#    #+#             */
/*   Updated: 2016/08/23 00:14:03 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft.h"
# define BUFF_SIZE 2000000

int		get_next_line(int const fd, char **line);

typedef struct		s_gnl
{
	char			*str;
	char			*line;
	char			*tmp;
	char			*buff;
	int				i;
	int				l_len;
	int				is_ln;
}					t_gnl;

#endif
