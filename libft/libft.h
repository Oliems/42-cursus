/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:46:31 by mbarberi          #+#    #+#             */
/*   Updated: 2023/01/03 15:47:02 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

/* DEFINES */
# define OCTAL "01234567"
# define HX_LO "0123456789abcdef"
# define HX_HI "0123456789ABCDEF"

/* STDLIB */
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t number, size_t size);

/* CTYPE */
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

/* STRING */
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *b, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *b, int c, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strdup(const char *str);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t len);
int			ft_memcmp(const void *b1, const void *b2, size_t len);

/* EXTRAS */
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* BONUS */
typedef struct s_list	t_list;
struct	s_list
{
	char	*content;
	t_list	*next;
};

int			ft_lstsize(t_list *lst);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));

/* PERSONAL */
int			ft_isupper(int c);
int			ft_islower(int c);
int			ft_isspace(int c);
int			ft_permute(void *b, int n);
int			ft_permute_int(int *arr, int n);
int			ft_ndigit(int n, int baselen);
char		*ft_itoa_base(intmax_t n, char *base);
void		ft_reverse(char *s);
uintmax_t	ft_abs(intmax_t i);

/* GNL */
# ifndef EOF
#  define EOF -1
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef CHUNK_SIZE
#  define CHUNK_SIZE 16
# endif

typedef struct s_file	t_file;
struct s_file
{
	int		i;
	int		rv;
	char	buf[BUFFER_SIZE];
};
/* rv -> return value for read() */

int			ft_getchar(int fd, t_file *file);
char		*get_next_line(int fd);
char		*ft_tostr(t_list *list);
t_list		*ft_tolist(t_list *list, t_file *file, int fd);

#endif
