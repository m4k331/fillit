/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:32:14 by ahugh             #+#    #+#             */
/*   Updated: 2018/12/23 23:21:16 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_square		*create_square(short n)
{
	t_square	*sq;
	short		i;

	i = -1;
	if ((sq = (t_square*)malloc(sizeof(t_square))))
	{
		if ((sq->sq = (char**)malloc(sizeof(char*) * n)))
		{
			while (++i < n)
				if (!(sq->sq[i] = (char*)malloc(sizeof(char) * n)))
					break ;
				else
					ft_memset(sq->sq[i], 46, n);
			if (i != n)
				ft_arrdel((void**)&sq->sq);
		}
		else
			ft_memdel((void**)&sq);
		sq->n = n;
	}
	return (sq);
}

void			print_square(t_square *sq)
{
	short		i;
	short		j;

	i = 0;
	while (!(j = 0) && i < sq->n)
	{
		while (j < sq->n)
		{
			ft_putchar(sq->sq[i][j]);
			j++;
		}
		ft_putchar(10);
		i++;
	}
}
