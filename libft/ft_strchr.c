/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:04:32 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:04:33 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int search_char)
{
	const char	*p;

	p = str;
	while (*p)
	{
		if (*p == (char)search_char)
			return ((char *)p);
		p++;
	}
	if (*p == (char)search_char)
		return ((char *)p);
	return (NULL);
}
