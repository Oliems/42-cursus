/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:09:32 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/16 13:58:50 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>
# include <stdint.h>

/* STANDARD */
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *d, const char *s, size_t n);
size_t		ft_strlcat(char *d, const char *s, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *d, const void *s, size_t n);
void		*ft_memmove(void *d, const void *s, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strdup(const char *str);
char		*ft_strnstr(const char *h, const char *n, size_t m);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/* NON-STANDARD */
void		*ft_memrchr(const void *s, int c, size_t n);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
#endif
