/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:16:17 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:04:14 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	hex_string_size(unsigned long num)
{
	int	size;

	size = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		size++;
	}
	return (size);
}

char	*int_to_hex(unsigned long num, int type)
{
	char	*str;
	char	*hex_chars;
	int		size;
	int		i;

	if (type == 1)
		hex_chars = ft_strdup("0123456789ABCDEF");
	else
		hex_chars = ft_strdup("0123456789abcdef");
	size = hex_string_size(num);
	i = size - 1;
	str = malloc(size + 1);
	str[size] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return (free(hex_chars), str);
	}
	while (num > 0)
	{
		str[i] = hex_chars[num % 16];
		num /= 16;
		i--;
	}
	return (free(hex_chars), str);
}
