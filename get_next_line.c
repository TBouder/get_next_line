/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:59:39 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/04 22:15:32 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

static int		r_value(char **str, int i)
{
	*str = NULL;
	free(*str);
	return (i);	
}

static char		*helper(char *str, char **line)
{
	char	*dst;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_linelen(str, 0);
	dst = ft_strnew(len);
	while (i < len)
	{
		dst[i] = str[j];
		j += 1;
		i += 1;
	}
	str += j;
	*line = ft_strnew(len + 1);
	ft_strncpy(*line, dst, len);
	ft_strdel(&dst);
	return (str);
}

static int		ft_extract_line(int const fd, char **str)
{
	int				i;
	char			*buffer;
	t_list			*list;
	t_list			*tmp;

	list = NULL;
	buffer = ft_strnew(BUFF_SIZE);
	while ((i = read(fd, buffer, BUFF_SIZE)) > 0)
		ft_lstend(&list, buffer, i);
	if (i == -1)
		return (-1);
	*str = ft_strnew(ft_lstcontentsize(list));
	while (list)
	{
		tmp = list;
		list = list->next;
		*str = ft_strncat(*str, tmp->content, tmp->content_size);
		free(tmp->content);
		free(tmp);
	}
	ft_strdel(&buffer);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char		*str = NULL;
	int				i;

	if (line == NULL)
		return (-1);
	if (!str)
	{
		i = ft_extract_line(fd, &str);
		if (i == -1)
			return (-1);
		if (str == NULL)
		{
			ft_strdel(&str);
			return (0);
		}
	}
	str = helper(str, line);
	if (*str == '\0')
		return(r_value(&str, 0));
	*str == '\n' ? str++ : 0;
	if (*str == '\0')
		return(r_value(&str, 1));
	return (1);
}