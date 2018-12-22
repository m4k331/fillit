/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:06:09 by ahugh             #+#    #+#             */
/*   Updated: 2018/12/22 23:25:29 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

char		read_tet(int fd, char tet[SZ_TET][SZ_TET])
{
	char	i;
	char	j;
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

void		catch_coords(t_tet *tet, char rd[SZ_TET][SZ_TET], char i, char j)
{
	if (rd[i][j] == 35 && (rd[i][j] = 46))
		add_coord_tet(tet, i, j);
	if (i + 1 < SZ_TET && ++i)
		rd[i][j] == 35 ? catch_coords(tet, rd, i, j) : i--;
	if (j + 1 < SZ_TET && ++j)
		rd[i][j] == 35 ? catch_coords(tet, rd, i, j) : j--;
	if (j - 1 > -1)
		rd[i][--j] == 35 ? catch_coords(tet, rd, i, j) : j++;
	if (i - 1 > -1)
		rd[--i][j] == 35 ? catch_coords(tet, rd, i, j) : i++;
}

void		normallize_coords(t_tet *tet)
{
	char	min_i;
	char	min_j;
	char	i;

	i = 0;
	min_i = tet->coords[0][0];
	min_j = tet->coords[0][1];
	while (++i < SZ_TET)
	{
		if (tet->coords[i][0] < min_i)
			min_i = tet->coords[i][0];
		if (tet->coords[i][1] < min_j)
			min_j = tet->coords[i][1];
	}
	i = -1;
	while (++i < SZ_TET)
	{
		tet->coords[i][0] -= min_i;
		tet->coords[i][1] -= min_j;
	}
}

char		set_coords_tet(t_tet *tet, char rd[SZ_TET][SZ_TET])
{
	char	i;
	char	j;

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
	char	i;
	char	rt;

	i = 0;
	rt = -1;
	while ((rt != 0) && (rt = read_tet(fd, rd)) > -1)
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
	return (rt ? 0 : 1);
}
