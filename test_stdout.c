#include "../get_next_line.h"

int		main(void)
{
	char	*line = NULL;

	while (get_next_line(1, &line))
	{
		ft_putendl(line);
		ft_strdel(&line);
	}

	return (0);
}

/*
 * execute binary
 * (program waits for input)
 * type some characters, hit return to separate lines
 * ^D to end input
 */