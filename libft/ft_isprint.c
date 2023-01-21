/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:55:09 by mbarberi          #+#    #+#             */
/*   Updated: 2022/11/07 16:06:33 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The isprint(3) function tests for any printing character, including
** space.
*/
int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
