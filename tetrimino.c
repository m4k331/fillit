/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 17:13:00 by ahugh             #+#    #+#             */
/*   Updated: 2018/12/26 16:58:08 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet		*new_tet(char ch)
{
	t_tet	*tet;

	if ((tet = (t_tet*)malloc(sizeof(t_tet))))
	{
		tet->amount = 0;
		tet->print = ch;
	}
	return (tet);
}

void		add_coord_tet(t_tet *tet, short i, short j)
{
	if (++tet->amount <= SZ_TET)
	{
		tet->coords[tet->amount - 1][0] = i;
		tet->coords[tet->amount - 1][1] = j;
	}
	else
		tet->amount = -1;
}

char		insert_tet(t_tet *tet, t_square *sq, short i, short j)
{
	short	num_coord;
	short	mod_i;
	short	mod_j;

	num_coord = -1;
	mod_i = 0;
	mod_j = 0;
	while (++num_coord < SZ_TET)
	{
		mod_i = tet->coords[num_coord][0] + i;
		mod_j = tet->coords[num_coord][1] + j;
		if (mod_i < sq->n && mod_j < sq->n && sq->sq[mod_i][mod_j] == 46)
			sq->sq[mod_i][mod_j] = tet->print;
		else
		{
			while (num_coord--)
			{
				mod_i = tet->coords[num_coord][0] + i;
				mod_j = tet->coords[num_coord][1] + j;
				sq->sq[mod_i][mod_j] = 46;
			}
			return (0);
		}
	}
	return (1);
}
