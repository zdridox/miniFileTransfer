/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:19:53 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:11:08 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static t_gnl_list	*_buffers;
	t_gnl_list			*current_fd;
	char				*line;
	int					bytes_total;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(BUFFER_SIZE + 1);
	line[0] = '\0';
	current_fd = handle_fd(&_buffers, fd);
	if (!current_fd)
		return (NULL);
	bytes_total = current_fd->bytes_read;
	load_buffer(&line, current_fd, &bytes_total, fd);
	grab_data(&line, current_fd, &bytes_total, fd);
	if (!line)
		return (NULL);
	handle_buffer(&line, current_fd, &bytes_total, &_buffers);
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}

void	handle_buffer(char **line, t_gnl_list *current_fd, int *bytes_total,
		t_gnl_list **_buffers)
{
	int	remaining;

	remaining = 0;
	if (current_fd && check_for_newline(*line, *bytes_total) >= 0
		&& (*line)[0] != '\0')
	{
		(*line)[check_for_newline(*line, *bytes_total) + 1] = '\0';
		remaining = current_fd->bytes_read
			- (check_for_newline(current_fd->buffer, current_fd->bytes_read)
				+ 1);
		if (remaining > 0)
			ft_memmove(current_fd->buffer,
				&current_fd->buffer[check_for_newline(current_fd->buffer,
					current_fd->bytes_read) + 1], remaining);
		current_fd->bytes_read = remaining;
		if (current_fd->fd == 0 && remaining == 0)
			free_buffer(_buffers, current_fd->fd);
	}
	else
		free_buffer(_buffers, current_fd->fd);
}

void	grab_data(char **line, t_gnl_list *current_fd, int *bytes_total, int fd)
{
	while (check_for_newline(*line, *bytes_total) < 0)
	{
		current_fd->bytes_read = read(fd, current_fd->buffer, BUFFER_SIZE);
		if (current_fd->bytes_read <= 0)
			break ;
		*bytes_total += current_fd->bytes_read;
		line_resize(line, *bytes_total - current_fd->bytes_read, *bytes_total
			+ 1);
		if (!*line)
			return ;
		ft_memmove(&(*line)[*bytes_total - current_fd->bytes_read],
			current_fd->buffer, current_fd->bytes_read);
		(*line)[*bytes_total] = '\0';
	}
	if (current_fd->bytes_read < 0)
		(*line)[0] = '\0';
}

void	load_buffer(char **line, t_gnl_list *current_fd, int *bytes_total,
		int fd)
{
	if (current_fd->buffer[0] == '\0')
	{
		current_fd->bytes_read = read(fd, current_fd->buffer, BUFFER_SIZE);
		*bytes_total += current_fd->bytes_read;
		if (current_fd->bytes_read <= 0)
		{
			(*line)[0] = '\0';
			return ;
		}
		ft_memmove(*line, current_fd->buffer, *bytes_total);
		(*line)[*bytes_total] = '\0';
	}
	else
	{
		ft_memmove(*line, current_fd->buffer, *bytes_total);
		(*line)[*bytes_total] = '\0';
	}
}

t_gnl_list	*handle_fd(t_gnl_list **list, int fd)
{
	t_gnl_list	*p;

	p = *list;
	while (p != NULL)
	{
		if (p->fd == fd)
			return (p);
		p = p->next;
	}
	return (add_fd_back(list, fd));
}
