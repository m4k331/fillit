/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:23:13 by ahugh             #+#    #+#             */
/*   Updated: 2018/12/05 10:50:58 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	max_size;

	max_size = -1;
	str = NULL;
	if (!(max_size == size) && (str = (char*)malloc(sizeof(char) * (size + 1))))
		ft_bzero(str, size + 1);
	return (str);
}
