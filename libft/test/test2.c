#include "libft.h"
#include <strings.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("LICENSE", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
		printf("%s", line);
	close(fd);
	return (0);
}
