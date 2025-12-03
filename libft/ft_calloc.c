/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:03:11 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:03:11 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t			i;
	unsigned char	*p;

	if (nitems != 0 && nitems * size / nitems != size)
		return (NULL);
	i = 0;
	p = malloc(nitems * size);
	if (!p)
	{
		return (NULL);
	}
	while (i < nitems * size)
	{
		p[i++] = 0;
	}
	return ((void *)p);
}
