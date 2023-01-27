/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:19:38 by mbarberi          #+#    #+#             */
/*   Updated: 2023/01/27 15:07:40 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

/* Substitute a '%' construct with the correct value. */
int	ft_subperc(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(*ap, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(*ap, char *), 1));
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		return (ft_putnbr_base(va_arg(*ap, size_t), HX_LO) + 2);
	}
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(*ap, int), 1));
	if (c == 'u')
		return (ft_putnbr_base(va_arg(*ap, unsigned int), DECIM));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(*ap, unsigned int), HX_LO));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(*ap, unsigned int), HX_HI));
	if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (ft_putchar_fd(c, 1));
}

int	ft_printf(const char *s, ...)
{
	int		r;
	va_list	ap;

	if (!s || write(1, 0, 0) < 0)
		return (-1);
	if (!*s)
		return (0);
	r = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
			r += ft_putchar_fd(*s, 1);
		else
			r += ft_subperc(*++s, &ap);
		if (!*s++)
			break ;
	}
	va_end(ap);
	return (r);
}
