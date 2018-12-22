/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:21:42 by ahugh             #+#    #+#             */
/*   Updated: 2018/11/30 19:39:33 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*ph;
	const char	*pn;

	ph = haystack;
	pn = needle;
	if (!*needle)
		return ((char*)haystack);
	else
		while (*pn && *ph)
		{
			while (*pn++ == *ph && *ph++)
				if (!*pn)
					return ((char*)haystack);
			ph = ++haystack;
			pn = needle;
		}
	return (0);
}
