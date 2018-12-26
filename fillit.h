/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:06:41 by ahugh             #+#    #+#             */
/*   Updated: 2018/12/26 16:51:46 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/includes/libft.h"
# define SZ_TET 4
# define MAX_TET 26

typedef struct	s_tet
{
	short		coords[SZ_TET][2];
	short		amount;
	char		print;
}				t_tet;

typedef struct	s_square
{
	char		**sq;
	short		n;
	short		set_tet;
	short		max_tet;
}				t_square;

t_tet			*new_tet(char ch);
void			add_coord_tet(t_tet *tet, short i, short j);
char			get_tetriminos(int fd, t_tet *tets[MAX_TET]);
char			insert_tet(t_tet *tet, t_square *sq, short i, short j);
t_square		*create_square(short n, short max_tet);
void			del_square(t_square *sq);
void			print_square(t_square *sq);

#endif
