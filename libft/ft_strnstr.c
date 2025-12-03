/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:05:22 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:05:23 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	to_find_len;

	if (!*to_find)
		return ((char *)str);
	to_find_len = ft_strlen(to_find);
	i = 0;
	while (i < len && str[i])
	{
		j = 0;
		while (i + j < len && str[i + j] && str[i + j] == to_find[j])
			j++;
		if (j == to_find_len)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

// int main()
//{
//	char	str1[] = "test dup zupy";
//	char	str2[] = "dupy";
//
//	printf("%s\n", ft_strstr(str1, str2));
//	return (0);
//}
