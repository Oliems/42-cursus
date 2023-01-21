/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:20:03 by mbarberi          #+#    #+#             */
/*   Updated: 2022/11/29 14:21:37 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
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

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*head;

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

t_list	*ft_lstnew(void *content)
{
	t_list	*p;

	p = malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	p->chunk = ft_strdup((const char *)content);
	p->next = NULL;
	return (p);
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*p;

	i = 0;
	p = lst;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

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
