/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:52:57 by ahugh             #+#    #+#             */
/*   Updated: 2018/11/30 19:38:32 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	size_t	i;

	map = NULL;
	i = 0;
	if (s && f && (map = ft_strnew(ft_strlen(s))))
		while (s[i])
		{
			map[i] = f(s[i]);
			i++;
		}
	return (map);
}
