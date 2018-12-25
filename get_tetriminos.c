/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:06:09 by ahugh             #+#    #+#             */
/*   Updated: 2018/12/25 21:15:08 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char		read_tet(int fd, char tet[SZ_TET][SZ_TET])
{
	int		i;
	int		j;
	char	amount;

	i = 0;
	amount = 0;
	while (!(j = 0) && i < SZ_TET)
	{
		if (read(fd, tet[i], SZ_TET) == SZ_TET)
			while (j < SZ_TET && (tet[i][j] == 46 || tet[i][j] == 35))
				if (tet[i][j++] == 35)
					amount++;
		if (j != SZ_TET || read(fd, tet[++i], 1) != 1 || tet[i][0] != 10)
			return (-1);
	}
	if (amount == SZ_TET)
	{
		if (read(fd, &j, 1) == 0)
			return (0);
		else if (j == 10)
			return (1);
	}
	return (-1);
}

void		catch_coords(t_tet *tet, char rd[SZ_TET][SZ_TET], short i, short j)
{
	if (rd[i][j] == 35 && (rd[i][j] = 46))
		add_coord_tet(tet, i, j);
	if (i + 1 < SZ_TET && rd[i + 1][j] == 35)
		catch_coords(tet, rd, i + 1, j);
	if (j + 1 < SZ_TET && rd[i][j + 1] == 35)
		catch_coords(tet, rd, i, j + 1);
	if (i - 1 > -1 && rd[i - 1][j] == 35)
		catch_coords(tet, rd, i - 1, j);
	if (j - 1 > -1 && rd[i][j - 1] == 35)
		catch_coords(tet, rd, i, j - 1);
}

void		normallize_coords(t_tet *tet)
{
	char	i;
	char	j;
	short	n;

	i = tet->coords[0][0];
	j = tet->coords[0][1];
	n = 0;
	while (++n < SZ_TET)
		if (tet->coords[n][0] < i)
		{
			i = tet->coords[n][0];
			j = tet->coords[n][1];
		}
	n = -1;
	while (++n < SZ_TET)
	{
		tet->coords[n][0] -= i;
		tet->coords[n][1] -= j;
	}
}

char		set_coords_tet(t_tet *tet, char rd[SZ_TET][SZ_TET])
{
	short	i;
	short	j;

	i = 0;
	while (!(j = 0) && i < SZ_TET)
	{
		while (j < SZ_TET && tet->amount == 0)
			catch_coords(tet, rd, i, j++);
		i++;
	}
	if (tet->amount == SZ_TET)
	{
		normallize_coords(tet);
		return (1);
	}
	return (0);
}

char		get_tetriminos(int fd, t_tet *tets[MAX_TET])
{
	char	rd[SZ_TET][SZ_TET];
	short	i;
	char	rt;
	char	count_tet;

	i = 0;
	rt = -1;
	count_tet = 0;
	while ((rt != 0) && (rt = read_tet(fd, rd)) > -1 && ++count_tet)
	{
		if (!(tets[i] = new_tet(65 + i)) || \
		!set_coords_tet(tets[i], rd) || rt == -1)
		{
			while (i > -1)
			{
				if (tets[i])
					ft_memdel((void**)&tets[i]);
				i--;
			}
			return (0);
		}
		i++;
	}
	return (rt ? 0 : count_tet);
}
