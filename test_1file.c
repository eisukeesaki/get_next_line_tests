#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char	*line = NULL;
	int		fd;

	if ((fd = open("tests/input1.txt", O_RDONLY)) == 1)
		printf("file open error\n");
	else
		printf("fd of input1.txt is:%d\n", fd);

	printf("<<<<<<<<<<<<<<<<<<<< fd%d\n", fd);
	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	printf(">>>>>>>>>>>>>>>>>>>> fd%d\n", fd);
	
	close(fd);

	// while (1); // keep process running

	return (0);
}
