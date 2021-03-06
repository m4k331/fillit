/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:32:14 by ahugh             #+#    #+#             */
/*   Updated: 2018/12/26 16:54:00 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			del_square(t_square *sq)
{
	short		i;

	i = -1;
	if (sq)
	{
		while (++i < sq->n)
			ft_memdel((void**)&sq->sq[i]);
		ft_memdel((void**)&sq);
	}
}

t_square		*create_square(short n, short max_tet)
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
			sq->n = i;
			sq->set_tet = 0;
			sq->max_tet = max_tet;
			if (i != n)
				del_square(sq);
		}
		else
			ft_memdel((void**)&sq);
	}
	return (sq);
}

void			print_square(t_square *sq)
{
	short		i;
	short		j;

	i = 0;
	if (sq)
	{
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
}
