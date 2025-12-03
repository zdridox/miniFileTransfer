/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:16:21 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/03 13:16:23 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	putstr(char *str)
{
	int	size;

	if (str == NULL)
		return (putstr("(null)"));
	size = 0;
	while (*str != '\0')
	{
		write(1, &(*str), 1);
		size++;
		str++;
	}
	return (size);
}

int	putnbr(int nbr)
{
	int		size;
	char	*nbr_t;

	nbr_t = ft_itoa(nbr);
	size = putstr(nbr_t);
	free(nbr_t);
	return (size);
}

int	putunbr(unsigned int nbr)
{
	int		size;
	char	*nbr_t;

	nbr_t = unsigned_itoa(nbr);
	size = putstr(nbr_t);
	free(nbr_t);
	return (size);
}

int	printpointer(void *p)
{
	int		size;
	char	*hex;

	if (p == 0)
		return (putstr("(nil)"));
	size = putstr("0x");
	hex = int_to_hex((unsigned long)p, 2);
	size += putstr(hex);
	return (free(hex), size);
}

int	puthex(unsigned long num, int type)
{
	char	*hex;
	int		size;

	hex = int_to_hex(num, type);
	size = putstr(hex);
	return (free(hex), size);
}
