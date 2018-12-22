/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:37:18 by ahugh             #+#    #+#             */
/*   Updated: 2018/12/01 13:07:04 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	ln;
	char	size;
	char	*nbr;

	size = 1;
	ln = n;
	while (ln != 0 && ++size)
		ln /= 10;
	if (!(nbr = ft_strnew(n <= 0 ? size : --size)))
		return (NULL);
	ln = n;
	if (ln < 0 && (nbr[0] = 45))
		ln *= -1;
	while (size--)
	{
		nbr[(int)size] = (ln % 10) + 48;
		if (!(ln /= 10))
			break ;
	}
	return (nbr);
}
