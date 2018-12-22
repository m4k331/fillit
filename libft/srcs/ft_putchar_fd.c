/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:02:02 by ahugh             #+#    #+#             */
/*   Updated: 2018/11/30 19:36:35 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (fd > -1)
	{
		if (uc < 128)
			write(fd, &c, 1);
		else
		{
			uc = (unsigned char)c >> 6 | 0xC0;
			write(fd, &uc, 1);
			uc = ((unsigned char)c & 0x3F) | 0x80;
			write(fd, &uc, 1);
		}
	}
}
