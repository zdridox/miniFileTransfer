/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:20:06 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:08:45 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_for_newline(char *buff, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	line_resize(char **line, int size, int new_size)
{
	char	*buff_line;

	buff_line = malloc(size);
	ft_memmove(buff_line, *line, (size_t)size);
	free(*line);
	*line = malloc(new_size);
	ft_memmove(*line, buff_line, (size_t)size);
	(*line)[size] = '\0';
	free(buff_line);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
}

void	free_buffer(t_gnl_list **buffers, int fd)
{
	t_gnl_list	*p;
	t_gnl_list	*p2;

	p = *buffers;
	if (p->next == NULL)
	{
		free(p->buffer);
		free(p);
		*buffers = NULL;
		return ;
	}
	while (p != NULL)
	{
		if (p->next && p->next->fd == fd)
		{
			p2 = p->next->next;
			free(p->next->buffer);
			free(p->next);
			p->next = p2;
			break ;
		}
		p = p->next;
	}
}

t_gnl_list	*add_fd_back(t_gnl_list **list, int fd)
{
	t_gnl_list	*node;
	t_gnl_list	*p;

	p = *list;
	node = malloc(sizeof(t_gnl_list));
	if (!node)
		return (NULL);
	node->buffer = malloc(BUFFER_SIZE);
	if (!node->buffer)
		return (NULL);
	node->buffer[0] = '\0';
	node->bytes_read = 0;
	node->fd = fd;
	node->next = NULL;
	if (!*list)
	{
		*list = node;
		return (node);
	}
	while (p->next != NULL)
		p = p->next;
	p->next = node;
	return (node);
}
