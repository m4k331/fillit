/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:54:58 by ahugh             #+#    #+#             */
/*   Updated: 2018/12/05 20:00:03 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	char				sign;
	unsigned char		len;
	unsigned long long	result;

	while (!(len = 0) && ft_isspace(*str))
		++str;
	if ((sign = 1) && !ft_isdigit(*str) && *str == 45)
		sign = -1;
	if (!(result = 0) && (*str == 43 || *str == 45))
		++str;
	while (*str == 48)
		str++;
	while (ft_isdigit(*str) && (++len < 21))
		result = result * 10 + (*str++ - 48);
	if (sign > 0 && (len > 19 || result > 9223372036854775807))
		return (-1);
	if (sign < 0 && (len > 19 || result > 9223372036854775808ULL))
		return (0);
	return (sign * result);
}
