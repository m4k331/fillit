/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 17:14:39 by ahugh             #+#    #+#             */
/*   Updated: 2018/12/22 19:46:41 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H
# include "fillit.h"

typedef struct	s_tet
{
	char		coords[SZ_TET][2];
	char		amount;
	char		print;
}				t_tet;

t_tet			*new_tet(char print);
void			add_coord_tet(t_tet *tet, char i, char j);

#endif
