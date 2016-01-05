#include "get_next_line.h"
#include <stdio.h>
#include "libft.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (ac == 2 && fd != -1)
	{
		get_next_line(fd, &line);
		printf("Premier passage : %s\n", line);

		free(line);

		get_next_line(fd, &line);
		printf("Deuxieme passage : %s\n", line);

		free(line);

		get_next_line(fd, &line);
		printf("Troisieme passage : %s\n", line);

		free(line);

		get_next_line(fd, &line);
		printf("Quatrieme passage : %s\n", line);

		free(line);

		get_next_line(fd, &line);
		 printf("Cinquieme passage : %s\n", line);
		 

	}
	else
	{
		printf("Error\n");
	}
	ft_strdel(&line);
	return (0);
}
