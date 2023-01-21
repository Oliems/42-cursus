/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:54:06 by mbarberi          #+#    #+#             */
/*   Updated: 2022/11/14 10:17:48 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The calloc() function allocates space for /number/ objects, each /size/ bytes
** in length.  The result is identical to calling malloc() with an argument
** of ``number * size'', with the exception that the allocated memory is
** explicitly initialized to zero bytes.
*/
void	*ft_calloc(size_t number, size_t size)
{
	void	*p;

	p = malloc(number * size);
	if (!p)
		return (NULL);
	ft_bzero(p, number * size);
	return (p);
}
