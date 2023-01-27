/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:58:07 by mbarberi          #+#    #+#             */
/*   Updated: 2023/01/27 15:07:38 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

uint64_t	ft_strlen(const char *s)
{
	char	*p;

	p = (char *)s;
	while (*p)
		p++;
	return ((uint64_t)(p - s));
}

uint64_t	ft_abs(int64_t i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

int	ft_putnbr_base(uint64_t n, char *base)
{
	int		i;
	int		l;
	int		r;
	char	num[32];

	i = 0;
	r = 0;
	l = ft_strlen(base);
	if (!n)
		return (write(1, &base[0], 1));
	if (n < 0)
	{
		r += ft_putchar_fd('-', 1);
		n = ft_abs(n);
	}
	while (n)
	{
		num[i++] = base[n % l];
		n /= l;
	}
	while (--i >= 0)
		r += write(1, &num[i], 1);
	return (r);
}

int	ft_putnbr_fd(int64_t n, int fd)
{
	int		i;
	int		r;
	char	num[32];

	i = 0;
	r = 0;
	if (!n)
		return (write(fd, "0", 1));
	if (n < 0)
		r += ft_putchar_fd('-', fd);
	n = ft_abs(n);
	while (n)
	{
		num[i++] = n % 10 + '0';
		n /= 10;
	}
	while (--i >= 0)
		r += write(fd, &num[i], 1);
	return (r);
}
