/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:05:21 by ahugh             #+#    #+#             */
/*   Updated: 2018/12/02 22:13:03 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	wc;
	size_t	len;
	char	**result;

	i = 0;
	len = 0;
	wc = ft_wc(s, c);
	if (!(result = NULL) && s)
		if ((result = (char**)malloc(sizeof(char*) * ++wc)))
			while (!(result[i] = 0) && --wc)
			{
				len = 0;
				while (*s == c && *s)
					s++;
				while (*s != c && *s && ++len)
					s++;
				if ((result[i] = ft_strnew(len)))
					ft_strncpy(result[i++], s - len, len);
				else
					return (ft_arrdel((void**)result));
			}
	return (result);
}
