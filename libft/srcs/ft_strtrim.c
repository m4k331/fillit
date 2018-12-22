/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:37:22 by ahugh             #+#    #+#             */
/*   Updated: 2018/11/30 19:39:44 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	ln;

	if (!s)
		return (NULL);
	ln = ft_strlen(s);
	trim = (char*)s + ln - 1;
	while (ln && (*trim == '\t' || *trim == '\n' || *trim == ' '))
	{
		ln--;
		trim--;
	}
	while (ln && (*s == '\t' || *s == '\n' || *s == ' '))
	{
		ln--;
		s++;
	}
	if ((trim = ft_strnew(ln)))
		ft_strncpy(trim, s, ln);
	return (trim);
}
