/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:04:01 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:04:02 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t n)
{
	const unsigned char	*b1;
	const unsigned char	*b2;
	size_t				i;

	b1 = p1;
	b2 = p2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)b1[i] != (unsigned char)b2[i])
			return ((unsigned char)b1[i] - (unsigned char)b2[i]);
		i++;
	}
	return (0);
}
