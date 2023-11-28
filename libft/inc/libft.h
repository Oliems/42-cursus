/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:46:31 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/06 17:30:04 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# include "ft_ctype.h"
# include "ft_print.h"
# include "ft_list.h"
# include "ft_stdlib.h"
# include "ft_string.h"
# include "get_next_line.h"
# include "ft_printf.h"

/* PERSONAL */
int			ft_permute(void *b, int n);
int			ft_permute_int(int *arr, int n);
int			ft_ndigit(int n, int baselen);
uintmax_t	ft_abs(intmax_t n);

#endif
