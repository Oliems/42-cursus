/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 04:17:16 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/18 04:49:35 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

static int	f_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	f_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

time_t	f_atoi(const char *s)
{
	time_t		x;
	int			sign;

	x = 0;
	sign = 1;
	while (f_isspace(*s))
		s++;
	if (*s == '-')
		sign *= -1;
	if (*s == '-' || *s == '+')
		s++;
	while (f_isdigit(*s))
		x = x * 10 + *s++ - '0';
	return (x * sign);
}

static size_t	f_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}

void	f_perror(const char *s)
{
	if (!s || !*s)
		return ;
	write(STDERR_FILENO, s, f_strlen(s));
}
