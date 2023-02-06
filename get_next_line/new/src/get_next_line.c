/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:20:20 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/06 14:13:13 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl__bzero(void *b, size_t len)
{
	void	*p;

	p = b;
	if (!len)
		return ;
	while (len--)
		*(char *)p++ = '\0';
}

/**
 * @brief Read BUFFER_SIZE characters from the file and return them one by one.
 * @param fd The file descriptor to read from.
 * @param file A structure containing information about the opened file.
 * @return The next character or EOF if there is no more characters.
 */
int	gnl__getchar(int fd, t_file *file)
{
	if (file->i >= file->rv)
	{
		gnl__bzero(file->buf, BUFFER_SIZE);
		file->i = 0;
	}
	if (!file->i)
		file->rv = read(fd, file->buf, BUFFER_SIZE);
	if (file->i == file->rv && file->rv < BUFFER_SIZE)
		return (EOF);
	else
		return ((unsigned char)file->buf[file->i++]);
}

/**
 * @brief Turn the input into a linked list made of chunks of the input.
 * @param list The head of the linked list.
 * @param file A structure containing information about the opened file.
 * @param fd The file descriptor to read from.
 * @return Its first argument (the head of the linked list).
 */
t_gnl	*gnl__tolist(t_gnl *list, t_file *file, int fd)
{
	int		i;
	int		flush;
	char	buf[CHUNK_SIZE];

	i = 0;
	flush = 0;
	while (1)
	{
		while (i < CHUNK_SIZE - 1 && !flush)
		{
			buf[i] = gnl__getchar(fd, file);
			if (buf[i] == '\n' || buf[i] == EOF)
				flush = 1;
			i++;
		}
		if (buf[i - 1] == EOF)
			buf[i - 1] = '\0';
		buf[i] = '\0';
		gnl__lstadd_back(&list, gnl__lstnew(buf));
		if (flush)
			return (list);
		i = 0;
	}
}

/**
 * @brief Turn the chunks in the linked list into a string.
 * @param list The head of the linked list.
 * @return A string made of all smaller strings (chunks) stored in the
 * linked list.
 */
char	*gnl__tostr(t_gnl *list)
{
	int		i;
	char	*p;
	char	*str;
	t_gnl	*pl;

	str = malloc(gnl__lstsize(list) * CHUNK_SIZE + 1);
	if (!str)
		return (NULL);
	p = str;
	pl = list;
	while (pl)
	{
		i = 0;
		while (pl->chunk[i])
			*p++ = pl->chunk[i++];
		pl = pl->next;
	}
	*p = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char			*line;
	t_gnl			*list;
	static t_file	file;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		file.rv = 0;
		return (NULL);
	}
	list = gnl__lstnew("\0");
	list = gnl__tolist(list, &file, fd);
	line = gnl__tostr(list);
	gnl__lstclear(&list, free);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
