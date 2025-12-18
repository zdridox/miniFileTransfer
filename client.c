/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:28:07 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/30 21:42:45 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"
#include <sys/time.h>
#include <stdio.h>

t_data *g_data;
int offset;
struct timeval t1, t2;

char *progress_bar(void)
{
	char *bar;
	int progress;
	int i;
	int j;

	i = 0;
	j = 0;
	bar = malloc(13);
	progress = ((g_data->bytes_send * 100) / g_data->bytes_size) / 10;
	bar[j++] = '[';
	while (i++ < progress)
		bar[j++] = '#';
	i = 0;
	while (i++ < 10 - progress)
		bar[j++] = '-';
	bar[11] = ']';
	bar[12] = '\0';
	return (bar);
}

void free_data(void)
{
	char *bar;

	bar = progress_bar();
	ft_printf("\r%d%% %s | bytes: %d/%d\n", ((g_data->bytes_send - offset) * 100) / (g_data->bytes_size - offset), bar, g_data->bytes_send - offset, (g_data->bytes_size - offset));
	gettimeofday(&t2, NULL);
	printf("this upload took: %.3fs (%.0fB/s)", (t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec) / 1e6, g_data->bytes_size / ((t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec) / 1e6));
	free(bar);
	free(g_data->message);
	free(g_data);
	exit(0);
}

void send_bit(void)
{
	if (!g_data->finished)
	{
		if ((g_data->buffer >> (7 - g_data->buffer_size)) & 1)
			kill(g_data->pid, SIGUSR1);
		else
			kill(g_data->pid, SIGUSR2);
		g_data->buffer_size++;
		if (g_data->buffer_size == 8)
		{
			g_data->buffer_size = 0;
			g_data->bytes_send++;
			if (g_data->bytes_send >= g_data->bytes_size)
				g_data->finished = 1;
			else
				g_data->buffer = *(++g_data->p);
		}
	}
}

void signal_handler(int sig)
{
	if (sig == SIGUSR1)
		send_bit();
}

void add_filename(char *name)
{
	int i;

	i = 0;
	while (name[i])
	{
		g_data->message[i] = name[i];
		i++;
	}
	g_data->message[i] = '\0';
}

void add_filesize(int size, int offset)
{
	char *size_str;
	int i;

	size_str = ft_itoa(size);
	i = 0;
	while (size_str[i])
	{
		g_data->message[offset + i] = size_str[i];
		i++;
	}
	g_data->message[offset + i] = '\0';
	free(size_str);
}

void read_file(char *file)
{
	char buffer[1024];
	int size = 0;
	int readed;
	int written = 0;
	int fd = open(file, O_RDONLY);
	char *name_pointer;
	char *size_str;

	name_pointer = ft_strrchr(file, '/');
	if (name_pointer != NULL)
		name_pointer++;
	else
		name_pointer = file;
	while ((readed = read(fd, buffer, 1024)) > 0)
		size += readed;
	close(fd);
	size_str = ft_itoa(size);
	offset = ft_strlen(name_pointer) + 1 + ft_strlen(size_str) + 1;
	size += offset;
	g_data->message = malloc(size);
	g_data->bytes_size = size;
	add_filename(name_pointer);
	add_filesize(size - offset, (int)ft_strlen(name_pointer) + 1);
	free(size_str);
	fd = open(file, O_RDONLY);
	while ((readed = read(fd, buffer, 1024)) > 0)
	{
		ft_memcpy(&g_data->message[written + offset], buffer, readed);
		written += readed;
	}
	close(fd);
}

int main(int argc, char **argv)
{
	char *bar;

	if (argc != 3 || !*argv[2])
		return (1);
	g_data = malloc(sizeof(t_data));
	g_data->pid = ft_atoi(argv[1]);
	g_data->bytes_send = 0;
	read_file(argv[2]);
	g_data->p = g_data->message;
	g_data->buffer = *g_data->p;
	g_data->finished = 0;
	g_data->buffer_size = 0;
	signal(SIGUSR1, signal_handler);
	gettimeofday(&t1, NULL);
	send_bit();
	while (1)
	{
		bar = progress_bar();
		ft_printf("\r%d%% %s | bytes: %d/%d", ((g_data->bytes_send - offset) * 100) / (g_data->bytes_size - offset), bar, g_data->bytes_send - offset, (g_data->bytes_size - offset));
		free(bar);
		if (g_data->finished)
			free_data();
	}
	return (0);
}
