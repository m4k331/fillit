/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 17:13:00 by ahugh             #+#    #+#             */
/*   Updated: 2018/12/22 17:43:27 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrimino.h"

t_tet		*new_tet(char print)
{
	t_tet	*tet;

	if ((tet = (t_tet*)malloc(sizeof(t_tet))))
	{
		tet->amount = 0;
		tet->print = print;
	}
	return (tet);
}

void		add_coord_tet(t_tet *tet, char i, char j)
{
	if (++tet->amount <= SZ_TET)
	{
		tet->coords[tet->amount - 1][0] = i;
		tet->coords[tet->amount - 1][1] = j;
	}
	else
		tet->amount = -1;
}
