/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:20:24 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/06 17:30:10 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> /* required for EOF */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef CHUNK_SIZE
#  define CHUNK_SIZE 16
# endif

typedef struct s_gnl	t_gnl;
typedef struct s_file	t_file;

struct s_gnl
{
	char	*chunk;
	t_gnl	*next;
};

/* rv -> return value for read() */
struct s_file
{
	int		i;
	int		rv;
	char	buf[BUFFER_SIZE];
};

/* UTILS */
int		gnl__lstsize(t_gnl *lst);
char	*gnl__strdup(const char *str);
t_gnl	*gnl__lstnew(void *content);
void	gnl__lstadd_back(t_gnl **lst, t_gnl *new);
void	gnl__lstclear(t_gnl **lst, void (*del)(void *));
void	gnl__bzero(void *b, size_t len);

/* GNL */
int		gnl__getchar(int fd, t_file *file);
char	*get_next_line(int fd);
char	*gnl__tostr(t_gnl *list);
t_gnl	*gnl__tolist(t_gnl *list, t_file *file, int fd);

#endif
