/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ndigit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:08:51 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/15 17:40:42 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Compute the number of digits an integer will have in a given base, including
** the minus sign if n < 0.
*/
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
