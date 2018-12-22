/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:15:35 by ahugh             #+#    #+#             */
/*   Updated: 2018/12/15 21:23:03 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t ptr_size, size_t new_size)
{
	void	*new_mem;

	if ((new_mem = malloc(new_size)))
	{
		if (ptr)
			ft_memcpy(new_mem, ptr, ptr_size < new_size ? ptr_size : new_size);
		ft_memdel(&ptr);
	}
	return (new_mem);
}
