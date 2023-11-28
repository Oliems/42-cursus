/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:00:58 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/07 16:06:00 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	split__empty_string(const char *s, char c)
{
	while (*s && *s == c)
		s++;
	if (!s)
		return (1);
	return (0);
}

static int	split__count_words(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		while (*s)
		{
			if ((*s == c) && ((*(s + 1) != c) && *(s + 1)))
				i++;
			s++;
		}
	}
	return (i + 1);
}

static char	**split__setup_arr(int size)
{
	char	**tmp;

	tmp = malloc((size + 1) * sizeof(char *));
	if (!tmp)
		return (NULL);
	tmp[size] = NULL;
	return (tmp);
}

static void	split__split(char *s, char **arr, int len, int c)
{
	int		i;
	char	*l;
	char	*r;

	i = 0;
	r = s;
	while (1)
	{
		l = r;
		while (*r && (*r != c))
			r++;
		*r = '\0';
		if (l != r)
			arr[i++] = ft_strdup(l);
		if ((r - s) == len)
			break ;
		r++;
	}
	free(s);
}

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings
 * obtained by splitting 's' using the character 'c' as a delimiter. The
 * array must end with a NULL pointer
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split or NULL if the
 * allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	char		**arr;

	if (!s || !*s || !c)
		return (NULL);
	if (split__empty_string(s, c))
	{
		arr = malloc(1);
		arr[0] = NULL;
		return (arr);
	}
	arr = split__setup_arr(split__count_words(s, c));
	split__split(ft_strdup(s), arr, ft_strlen(s), c);
	return (arr);
}
