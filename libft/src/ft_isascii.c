/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:50:28 by mbarberi          #+#    #+#             */
/*   Updated: 2022/11/10 19:27:10 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The isascii(3) function tests for an ASCII character, which is any
** character between 0 and octal 0177 inclusive.
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
