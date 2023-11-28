/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:54:23 by mbarberi          #+#    #+#             */
/*   Updated: 2023/01/05 17:57:14 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# define HX_LO "0123456789abcdef"
# define HX_HI "0123456789ABCDEF"
# define DECIM "0123456789"

/* FT_PRINTF */
int			ft_printf(const char *s, ...);
int			ft_subperc(char c, va_list *ap);
int			ft_putchar_fd(char c, int fd);

/* FT_UTILS_UTILS */
int			ft_putstr_fd(char *s, int fd);
int			ft_putnbr_base(int64_t n, char *base);
int			ft_putnbr_fd(int64_t n, int fd);
uint64_t	ft_strlen(const char *s);
uint64_t	ft_abs(int64_t i);

#endif
