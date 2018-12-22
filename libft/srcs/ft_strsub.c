/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:33:37 by ahugh             #+#    #+#             */
/*   Updated: 2018/12/05 14:19:41 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	max_size;

	substr = NULL;
	max_size = -1;
	max_size -= start;
	if (len <= max_size)
		if (s && (start + len) <= ft_strlen(s) && (substr = ft_strnew(len)))
			ft_strncpy(substr, s + start, len);
	return (substr);
}
