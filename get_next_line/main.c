/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:40:21 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/07 15:01:01 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <strings.h>
#include <fcntl.h>
#include <errno.h>

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

/* exits unexpectedly when using CTRL-Z then resuming */
/* int	main(void)
{
	char	*line;

	while ((line = get_next_line(1)) != NULL)
		printf("%s", line);
	return (0);
} */

/* int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test/kjv.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
		;
	close(fd);
	return (0);
} */

/* int main(void)
{
	int   fd;
	char *temp;

	fd = open("test/read_error.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	do
	{
		temp = get_next_line(fd);
		free(temp);
	} while (temp != NULL);
	printf("%s", get_next_line(fd));
	close(fd);

	fd = open("test/read_error.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);

	return (0);
} */

/* int main(void)
{
	int   fd;

	fd = open("test/limits.txt", O_RDONLY); // first open

	printf("%s", get_next_line(fd));
	close(fd);
	return(0);
} */
