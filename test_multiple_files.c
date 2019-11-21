#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char	*line = NULL;
	int		fd1;
	int		fd2;

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< fd1
	if ((fd1 = open("tests/input1.txt", O_RDONLY)) == 1)
	// if ((fd1 = open(1, O_RDONLY)) == 1) // read from stdin
		printf("file open error\n");
	else
		printf("fd of input1.txt is:%d\n", fd1);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> fd1

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< fd2
	if ((fd2 = open("tests/input2.txt", O_RDONLY)) == 1)
		printf("file open error\n");
	else
		printf("fd of input2.txt is:%d\n", fd2);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> fd2

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< read all from fd1
	printf("<<<<<<<<<<<<<<<<<<<< fd%d\n", fd1);
	while (get_next_line(fd1, &line))
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	printf(">>>>>>>>>>>>>>>>>>>>fd%d\n", fd1);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> read all from fd1
	
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< read all from fd2
	printf("<<<<<<<<<<<<<<<<<<<< fd%d\n", fd2);
	while (get_next_line(fd2, &line))
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	printf(">>>>>>>>>>>>>>>>>>>> fd%d\n", fd2);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> read all from fd2

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< close files
	close(fd1);
	close(fd2);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> close files

	// while (1); // keep process running

	return (0);
}

/* 
 * <test memory leaks>
 * while (1) to keep process running
 * open new terminal
 * leaks name_of_executable
 */