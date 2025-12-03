/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:04:24 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:04:24 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*nbr;
	char	*ptr;

	nbr = ft_itoa(n);
	ptr = nbr;
	while (*ptr)
	{
		write(fd, &*ptr, 1);
		ptr++;
	}
	free(nbr);
}
