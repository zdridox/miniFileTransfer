/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:16:03 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:03:28 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_sum(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*rev_str(char *str)
{
	int		i;
	int		size;
	char	temp;

	size = ft_strlen(str);
	i = 0;
	while (i < size / 2)
	{
		temp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = temp;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		size;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = digit_sum(n);
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[size - 1] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		result[i] = n % 10 + 48;
		n /= 10;
		i++;
	}
	return (result[size] = '\0', rev_str(result));
}

static int	u_digit_sum(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*unsigned_itoa(unsigned int num)
{
	char	*str;
	int		d_sum;
	int		i;

	d_sum = u_digit_sum(num);
	str = malloc(d_sum + 1);
	i = d_sum - 1;
	while (i != -1)
	{
		str[i] = num % 10 + 48;
		num /= 10;
		i--;
	}
	str[d_sum] = '\0';
	return (str);
}
