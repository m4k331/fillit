/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:14:23 by ahugh             #+#    #+#             */
/*   Updated: 2018/11/30 19:37:04 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long ln;

	if ((ln = n) < 0)
	{
		ft_putchar(45);
		ln *= -1;
	}
	while (ln > 9)
	{
		ft_putnbr(ln / 10);
		ln %= 10;
	}
	ft_putchar(ln + 48);
}
