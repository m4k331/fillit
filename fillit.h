/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:06:41 by ahugh             #+#    #+#             */
/*   Updated: 2018/12/23 23:45:16 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/includes/libft.h"
# define SZ_TET 4
# define MAX_TET 26

typedef struct	s_tet
{
	char		coords[SZ_TET][2];
	char		amount;
	char		print;
}				t_tet;

typedef struct	s_square
{
	char		**sq;
	short		n;
}				t_square;

t_tet			*new_tet(char ch);
void			add_coord_tet(t_tet *tet, char i, char j);
char			insert_tet(t_tet *tet, t_square *sq, short i, short j);
char			get_tetriminos(int fd, t_tet *tets[MAX_TET]);
void			print_square(t_square *sq);
t_square		*create_square(short n);

#endif
