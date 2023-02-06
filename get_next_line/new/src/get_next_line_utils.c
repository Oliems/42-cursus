/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:20:03 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/06 14:07:23 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl__strdup(const char *str)
{
	size_t	l;
	char	*p;

	if (!str)
		return (NULL);
	p = (char *)str;
	while (*p)
		p++;
	l = (size_t)(p - str);
	p = malloc(l + 1);
	if (!p)
		return (NULL);
	p[l] = '\0';
	while (l--)
		p[l] = str[l];
	return (p);
}

void	gnl__lstclear(t_gnl **lst, void (*del)(void *))
{
	t_gnl	*tmp;
	t_gnl	*head;

	if (!lst || !del)
		return ;
	head = *lst;
	while (head)
	{
		tmp = head;
		head = head->next;
		(del)((void *)(tmp->chunk));
		tmp->chunk = NULL;
		tmp->next = NULL;
		free(tmp);
		tmp = NULL;
	}
	*lst = NULL;
}

t_gnl	*gnl__lstnew(void *content)
{
	t_gnl	*p;

	p = malloc(sizeof(t_gnl));
	if (!p)
		return (NULL);
	p->chunk = gnl__strdup((const char *)content);
	p->next = NULL;
	return (p);
}

int	gnl__lstsize(t_gnl *lst)
{
	int		i;
	t_gnl	*p;

	i = 0;
	p = lst;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}

void	gnl__lstadd_back(t_gnl **lst, t_gnl *new)
{
	t_gnl	*p;

	p = *lst;
	while (p)
	{
		if (!(p->next))
			break ;
		p = p->next;
	}
	if (p)
	{
		p->next = new;
		return ;
	}
	lst[0] = new;
}
