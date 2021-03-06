/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:19:03 by ahugh             #+#    #+#             */
/*   Updated: 2018/12/26 16:53:09 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			init_size_square(short amount_tet)
{
	short		sz;
	short		amount_sq;

	sz = 0;
	amount_sq = amount_tet * SZ_TET;
	while (++sz)
		if (sz * sz >= amount_sq)
			break ;
	return (sz);
}

char			fill_square(t_tet *tets[MAX_TET], t_square **sq, short i, short j)
{
	t_square	*ex_sq;

	while (!(ex_sq = 0) && i < (*sq)->n && (*sq)->max_tet != (*sq)->set_tet)
	{
		while (j < (*sq)->n)
		{
			if (insert_tet(tets[(*sq)->set_tet], (*sq), i, j))
				if (++(*sq)->set_tet && fill_square(tets, sq, i, j))
					return ((*sq)->max_tet == (*sq)->set_tet);
			j++;
		}
		i++;
		j = 0;
	}
	if ((*sq)->max_tet != (*sq)->set_tet)
	{
		ex_sq = create_square(++(*sq)->n, (*sq)->max_tet);
		del_square(*sq);
		*sq = ex_sq;
		fill_square(tets, sq, 0, 0);
	}
	return (1);
}

int				main(int ac, char **av)
{
	int			fd;
	short		n;
	t_tet		*tets[MAX_TET];
	t_square	*sq;

	fd = -1;
	sq = 0;
	if (!(n = 0) && ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) != -1)
		{
			if ((n = get_tetriminos(fd, tets)))
				if ((sq = create_square(init_size_square(n), n)))
				{
					n = 0;
					if (fill_square(tets, &sq, 0, 0) && (n = 1))
						print_square(sq);
				}
			fd = close(fd);
		}
		(fd == -1 || !n || !sq) ? ft_putstr("error\n") : 1;
		(sq) ? del_square(sq) : 1;
	}
	else
		ft_putstr_fd("usage: fillit target_file\n", 2);
	return (0);
}
