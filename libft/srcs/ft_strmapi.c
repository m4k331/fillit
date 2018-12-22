/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:08:25 by ahugh             #+#    #+#             */
/*   Updated: 2018/11/30 19:38:37 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	size_t	i;

	map = NULL;
	i = 0;
	if (s && f && (map = ft_strnew(ft_strlen(s))))
		while (s[i])
		{
			map[i] = f(i, s[i]);
			i++;
		}
	return (map);
}
