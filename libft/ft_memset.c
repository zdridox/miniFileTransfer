/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:04:10 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:04:10 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, unsigned int c, size_t n)
{
	unsigned char	*p;

	p = ptr;
	while (n--)
		*p++ = (unsigned char)c;
	return (ptr);
}
