/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 19:02:47 by tbouder           #+#    #+#             */
/*   Updated: 2016/07/28 19:02:51 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main (int ac, char **av)
{
	int		i;
	char	*line;
	int		fd;
	int		ret;

	i = 0;
	fd = ac == 2 ? open(av[1], O_RDONLY) : 0;
	line = NULL;
	ret = 0;
	if (ac == 2 || (ac == 1 && fd == 0))
	{
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			ft_putstr(line);
			ft_putstr(" : ");
			ft_nbrendl(ret);
			ft_strdel(&line);
			line = NULL;
		}
	}
	close(fd);
	ft_strdel(&line);
	return (0);
}
