/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:16:10 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/03 13:16:12 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_type(char type, va_list args)
{
	char	c;

	if (type == 'c')
	{
		c = (char)va_arg(args, int);
		return (write(1, &c, 1));
	}
	if (type == 's')
		return (putstr(va_arg(args, char *)));
	if (type == 'd' || type == 'i')
		return (putnbr(va_arg(args, int)));
	if (type == 'u')
		return (putunbr(va_arg(args, unsigned int)));
	if (type == '%')
		return (write(1, "%", 1));
	if (type == 'X')
		return (puthex((unsigned long)va_arg(args, unsigned int), 1));
	if (type == 'x')
		return (puthex((unsigned long)va_arg(args, unsigned int), 2));
	if (type == 'p')
		return (printpointer(va_arg(args, void *)));
	return (0);
}

int	str_validator(const char *str)
{
	int		str_size;
	char	*valid_types;
	int		i;

	i = 0;
	valid_types = ft_strdup("cspdiuxX%");
	str_size = ft_strlen(str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i - 1] != '%' && i == str_size - 1)
			return (free(valid_types), -1);
		if (str[i] == '%' && char_index(valid_types, str[i + 1]) == -1 && str[i
				- 1] != '%')
			return (free(valid_types), -1);
		i++;
	}
	return (free(valid_types), 0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;

	size = 0;
	if (str_validator(str) < 0)
		return (-1);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			size += handle_type(*(str + 1), args);
			str++;
		}
		else
			size += write(1, str, 1);
		str++;
	}
	return (va_end(args), size);
}
