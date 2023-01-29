/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:51:28 by mbarberi          #+#    #+#             */
/*   Updated: 2023/01/27 18:05:43 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isnumber(const char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	if (!*s)
		return (0);
	while (ft_isdigit(*s))
		s++;
	if (!*s)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int			x;
	int			sign;

	x = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign *= -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
		x = x * 10 + *nptr++ - '0';
	return (x * sign);
}

/* PRINTF */

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
