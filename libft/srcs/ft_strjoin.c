/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:27:00 by ahugh             #+#    #+#             */
/*   Updated: 2018/11/30 19:38:16 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1s2;

	s1s2 = NULL;
	if (s1 && s2 && (s1s2 = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		ft_strcat(s1s2, s1);
		ft_strcat(s1s2, s2);
	}
	return (s1s2);
}
