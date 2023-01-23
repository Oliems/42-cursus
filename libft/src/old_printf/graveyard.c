/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graveyard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:54:20 by mbarberi          #+#    #+#             */
/*   Updated: 2023/01/04 16:28:00 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_substitute(char *s, t_list *lst, va_list ap);
char	*ft_ctostr(char c);
t_list	*ft_strtolst(const char *s, t_list *lst);

/*
** Turn the string provided to ft_printf into a linked list, with each block
** containing a word.
*/
t_list	*ft_strtolst(const char *s, t_list *lst)
{
	char	*os;
	char	*buf;

	os = (char *)s;
	buf = ft_calloc(1, ft_strlen(s) + 1);
	if (!buf)
		return (NULL);
	while (*os)
	{
		os = (char *)s;
		while (*s && !ft_isspace(*s))
			s++;
		ft_memcpy(buf, os, (s - os));
		ft_lstadd_back(&lst, ft_lstnew(buf));
		ft_bzero(buf, (s - os));
		os = (char *)s;
		while (*s && ft_isspace(*s))
			s++;
		ft_memcpy(buf, os, (s - os));
		ft_lstadd_back(&lst, ft_lstnew(buf));
		ft_bzero(buf, (s - os));
	}
	free(buf);
	return (lst);
}

/* Given a char c, returns a null-terminated string containing that character */
char	*ft_ctostr(char c)
{
	char *p;

	p = malloc(2);
	if (!p)
		return (NULL);
	p[0] = c;
	p[1] = '\0';
	return (p);
}

/* Replace a '%' construct with the correct value. */
void	ft_substitute(char *s, t_list *lst, va_list ap)
{
	int	c;

	c = *(s + 1);
	free(lst->content);
	if (c == 'c')
		lst->content = ft_ctostr((char)va_arg(ap, int));
	else if (c == 's')
		lst->content = ft_strdup(va_arg(ap, char *));
	else if (c == 'p')
		lst->content = ft_strdup(ft_itoa_base(va_arg(ap, size_t), HX_LO));
	else if (c == 'd' || c == 'i')
		lst->content = ft_strdup(ft_itoa(va_arg(ap, int)));
	else if (c == 'u')
		lst->content = ft_strdup(ft_itoa(va_arg(ap, unsigned int)));
	else if (c == 'x')
		lst->content = ft_strdup(ft_itoa_base(va_arg(ap, unsigned int), HX_LO));
	else if (c == 'X')
		lst->content = ft_strdup(ft_itoa_base(va_arg(ap, unsigned int), HX_HI));
	else if (c == '%')
		lst->content = ft_strdup("%");
	else
		lst->content = ft_ctostr(c);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	t_list	*lst;
	t_list	*olst;
	int		count;

	count = 0;
	va_start(ap, s);
	lst = ft_lstnew("\0");
	lst = ft_strtolst(s, lst);
	olst = lst;
	while (lst)
	{
		if (lst->content[0] == '%')
			ft_substitute(lst->content, lst, ap);
		ft_putstr_fd(lst->content, 1);
		count += ft_strlen(lst->content);
		lst = lst->next;
	}
	ft_lstclear(&olst, free);
	va_end(ap);
	return (count);
}

///////////////////
static int	ft_hasduplicates(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] == s[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_valid_base(char *base)
{
	if (!base[0] || !base[1])
		return (0);
	if (ft_hasduplicates(base))
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		base++;
	}
	return (1);
}

char	*ft_itoa_base(intmax_t n, char *base)
{
	char	*p;
	size_t	i;
	size_t	bl;
	int		size;

	if (!ft_valid_base(base))
		return (NULL);
	bl = ft_strlen(base);
	size = ft_ndigit(n, ft_strlen(base));
	p = malloc(size + 1);
	if (!p)
		return (NULL);
	p[size] = '\0';
	if (n < 0)
		p[0] = '-';
	else if (!n)
		p[0] = '0';
	n = ft_abs(n);
	while (n)
	{
		p[--size] = base[n % bl];
		n /= bl;
	}
	return (p);
}

int	ft_putfree(char *s, int fd)
{
	int	l;

	l = ft_strlen(s);
	if (s && fd)
	{
		if (write(fd, s, l))
		{
			free(s);
			return (l);
		}
	}
	free(s);
	return (0);
}

int	ft_ndigit(int n, int baselen)
{
	int	l;

	l = 0;
	if (n <= 0)
		l += 1;
	while (n)
	{
		l++;
		n /= baselen;
	}
	return (l);
}
