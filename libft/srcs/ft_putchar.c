/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:34:05 by ahugh             #+#    #+#             */
/*   Updated: 2018/11/30 19:36:41 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc < 128)
		write(1, &c, 1);
	else
	{
		uc = (unsigned char)c >> 6 | 0xC0;
		write(1, &uc, 1);
		uc = ((unsigned char)c & 0x3F) | 0x80;
		write(1, &uc, 1);
	}
}
