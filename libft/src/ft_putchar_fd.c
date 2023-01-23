/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:00:26 by mbarberi          #+#    #+#             */
/*   Updated: 2022/11/11 14:23:49 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_putchar_fd() function writes a character to the corresponding file
** descriptor. For example, 0 is the stdin, 1 is the stdout and 2 is stderr.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
