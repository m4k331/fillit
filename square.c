/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:32:14 by ahugh             #+#    #+#             */
/*   Updated: 2018/12/24 22:25:03 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_square		*create_square(char n, char max_tet)
{
	t_square	*sq;
	char		i;

	i = -1;
	if ((sq = (t_square*)malloc(sizeof(t_square))))
	{
		if ((sq->sq = (char**)malloc(sizeof(char*) * n)))
		{
			while (++i < (sq->n = n))
				if (!(sq->sq[i] = (char*)malloc(sizeof(char) * n)))
					break ;
				else
					ft_memset(sq->sq[i], 46, n);
			sq->set_tet = 0;
			sq->max_tet = max_tet;
			if (i != n && (n = 0))
			{
				while (n < i)
					ft_memdel((void**)&sq->sq[n]);
				ft_memdel((void**)&sq);
			}
		}
		else
			ft_memdel((void**)&sq);
	}
	return (sq);
}

void			del_square(t_square *sq)
{
	char		i;

	i = -1;
	if (sq)
	{
		while (++i < sq->n)
			ft_memdel((void**)&sq->sq[i]);
		ft_memdel((void**)&sq);
	}
}

void			print_square(t_square *sq)
{
	char		i;
	char		j;

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
