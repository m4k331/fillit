/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:45:22 by ahugh             #+#    #+#             */
/*   Updated: 2018/11/30 19:38:53 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*pdst;

	pdst = dst;
	while (len--)
		(*src) ? (*pdst++ = *src++) : ft_bzero(pdst++, 1);
	return (dst);
}
