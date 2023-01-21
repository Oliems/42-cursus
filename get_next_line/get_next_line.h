/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:20:24 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/07 14:49:00 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> /* required for EOF */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef CHUNK_SIZE
#  define CHUNK_SIZE 16
# endif

typedef struct s_list	t_list;
typedef struct s_file	t_file;

struct s_list
{
	char	*chunk;
	t_list	*next;
};

/* rv -> return value for read() */
struct s_file
{
	int		i;
	int		rv;
	char	buf[BUFFER_SIZE];
};

/* UTILS */
int		ft_lstsize(t_list *lst);
char	*ft_strdup(const char *str);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_bzero(void *b, size_t len);

/* GNL */
int		ft_getchar(int fd, t_file *file);
char	*get_next_line(int fd);
char	*ft_tostr(t_list *list);
t_list	*ft_tolist(t_list *list, t_file *file, int fd);

#endif
