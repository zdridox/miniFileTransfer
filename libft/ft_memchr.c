/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:03:59 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:03:59 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *str, unsigned int c, size_t n)
{
	unsigned char	*p;

	p = str;
	while (n-- > 0)
	{
		if (*p++ == (unsigned char)c)
			return ((void *)p - 1);
	}
	return (NULL);
}
