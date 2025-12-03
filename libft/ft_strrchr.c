/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:05:25 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:05:25 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int search_char)
{
	const char	*p;
	char		*g;

	p = s;
	g = NULL;
	while (*p)
	{
		if (*p == (char)search_char)
			g = (char *)p;
		p++;
	}
	if (*p == (char)search_char)
		g = (char *)p;
	return (g);
}
