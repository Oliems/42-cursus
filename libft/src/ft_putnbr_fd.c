/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:00:03 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/12 17:09:28 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_putnbr_fd() function writes the number n to corresponding file
** descriptor.
*/
void	ft_putnbr_fd(int n, int fd)
{
	size_t	nbr;

	nbr = ft_abs(n);
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}
