/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:54:14 by mbarberi          #+#    #+#             */
/*   Updated: 2022/11/11 17:18:39 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The isalnum(3) function tests for any character for which isalpha(3)
** or isdigit(3) is true.
*/
int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a'
			&& c <= 'z') || (c >= 'A' && c <= 'Z'));
}
