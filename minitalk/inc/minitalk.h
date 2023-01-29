/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:06:57 by mbarberi          #+#    #+#             */
/*   Updated: 2023/01/27 18:06:06 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int			ft_atoi(const char *nptr);
int			ft_isnumber(const char *s);

/* PRINTF */

# define HX_LO "0123456789abcdef"
# define HX_HI "0123456789ABCDEF"
# define DECIM "0123456789"

/* FT_PRINTF */
int			ft_printf(const char *s, ...);
int			ft_subperc(char c, va_list *ap);
int			ft_putchar_fd(char c, int fd);

/* FT_UTILS_UTILS */
int			ft_putstr_fd(char *s, int fd);
int			ft_putnbr_base(uint64_t n, char *base);
int			ft_putnbr_fd(int64_t n, int fd);
uint64_t	ft_strlen(const char *s);
uint64_t	ft_abs(int64_t i);

#endif
