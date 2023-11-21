/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:43:13 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/06 17:46:49 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Turn the string s into a linked list, with each block containing
 * a word.
 * @param s The string to turn into a linked list.
 * @param lst The head of the linked list.
 * @return A pointer to the head of the linked list.
 */
t_list	*ft_strtolst(const char *s, t_list *lst)
{
	char	*os;
	char	*buf;

	os = (char *)s;
	buf = ft_calloc(1, ft_strlen(s) + 1);
	if (!buf)
		return (NULL);
	while (*os)
	{
		os = (char *)s;
		while (*s && !ft_isspace(*s))
			s++;
		ft_memcpy(buf, os, (s - os));
		ft_lstadd_back(&lst, ft_lstnew(buf));
		ft_bzero(buf, (s - os));
		os = (char *)s;
		while (*s && ft_isspace(*s))
			s++;
		ft_memcpy(buf, os, (s - os));
		ft_lstadd_back(&lst, ft_lstnew(buf));
		ft_bzero(buf, (s - os));
	}
	free(buf);
	return (lst);
}
