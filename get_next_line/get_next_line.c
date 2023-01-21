/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:20:20 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/07 15:00:32 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *b, size_t len)
{
	void	*p;

	p = b;
	if (!len)
		return ;
	while (len--)
		*(char *)p++ = '\0';
}

/* read BUFFER_SIZE characters from the file and return them one by one */
int	ft_getchar(int fd, t_file *file)
{
	if (file->i >= file->rv)
	{
		ft_bzero(file->buf, BUFFER_SIZE);
		file->i = 0;
	}
	if (!file->i)
		file->rv = read(fd, file->buf, BUFFER_SIZE);
	if (file->i == file->rv && file->rv < BUFFER_SIZE)
		return (EOF);
	else
		return ((unsigned char)file->buf[file->i++]);
}

/* turn the input into a linked list containing chunks of the input */
t_list	*ft_tolist(t_list *list, t_file *file, int fd)
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
			buf[i] = ft_getchar(fd, file);
			if (buf[i] == '\n' || buf[i] == EOF)
				flush = 1;
			i++;
		}
		if (buf[i - 1] == EOF)
			buf[i - 1] = '\0';
		buf[i] = '\0';
		ft_lstadd_back(&list, ft_lstnew(buf));
		if (flush)
			return (list);
		i = 0;
	}
}

/* turn the chunks in the linked list into a string */
char	*ft_tostr(t_list *list)
{
	int		i;
	char	*p;
	char	*str;
	t_list	*pl;

	str = malloc(ft_lstsize(list) * CHUNK_SIZE + 1);
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
	t_list			*list;
	static t_file	file;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		file.rv = 0;
		return (NULL);
	}
	list = ft_lstnew("\0");
	list = ft_tolist(list, &file, fd);
	line = ft_tostr(list);
	ft_lstclear(&list, free);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
