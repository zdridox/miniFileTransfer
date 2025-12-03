/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:09:56 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:09:56 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char a)
{
	return (a == 9 || a == 10 || a == 11 || a == 12 || a == 13 || a == 32);
}

int	ft_atoi(const char *str)
{
	int		res;
	int		modulator;

	res = 0;
	modulator = 1;
	while (*str && is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (!ft_isdigit(*(str + 1)))
			return (0);
		if (*str == '-')
			modulator = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		res += *str - 48;
		if (ft_isdigit(*(str + 1)))
			res *= 10;
		str++;
	}
	return (res * modulator);
}
