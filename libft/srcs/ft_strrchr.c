/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:49:41 by ahugh             #+#    #+#             */
/*   Updated: 2018/11/30 19:39:17 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ocr;
	const char	*ps;

	ps = s;
	if (!c)
		return (ft_strchr(s, c));
	while (*s && (ocr = ft_strchr(s, c)))
		s = ++ocr;
	return (ps != s-- ? (char*)s : 0);
}
