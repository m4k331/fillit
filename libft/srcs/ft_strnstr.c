/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:42:13 by ahugh             #+#    #+#             */
/*   Updated: 2018/11/30 19:39:11 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*ph;
	const char	*pn;
	size_t		cp_len;

	ph = haystack;
	pn = needle;
	cp_len = len;
	if (!*needle)
		return ((char*)haystack);
	else
		while (*pn && *ph && len)
		{
			while (*pn++ == *ph && *ph++ && len)
				if (len-- && !*pn)
					return ((char*)haystack);
			ph = ++haystack;
			pn = needle;
			len = --cp_len;
		}
	return (0);
}
