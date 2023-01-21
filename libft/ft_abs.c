/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:53:30 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/15 17:50:37 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The abs() function computes the absolute value of the integer i. */
uintmax_t ft_abs(intmax_t i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}
