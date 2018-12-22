/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:44:00 by ahugh             #+#    #+#             */
/*   Updated: 2018/11/30 23:05:52 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	lsrc;

	ldst = 0;
	lsrc = ft_strlen(src);
	while (*dst++ && size && ++ldst)
		--size;
	if (size <= 1)
		return (ldst + lsrc);
	while (--size && *src)
		*(dst++ - 1) = *src++;
	*--dst = 0;
	return (ldst + lsrc);
}
