/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:28:11 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/30 22:04:55 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

t_buffer g_buffer;
int file_fd;
int downloaded_bytes = 0;
int filesize_todownload;
int filename_flag = 0;
int filename_index = 0;
int filesize_flag = 0;
int filesize_index = 0;
char filename[256];
char filesize[256];
char *path;

void signal_handler(int sig, siginfo_t *info, void *context)
{
	int client_pid;

	(void)context;
	client_pid = info->si_pid;
	g_buffer.size++;
	if (sig == SIGUSR1)
	{
		g_buffer.buffer = (g_buffer.buffer << 1) | 1;
	}
	else if (sig == SIGUSR2)
	{
		g_buffer.buffer = (g_buffer.buffer << 1) | 0;
	}
	if (g_buffer.size == 8)
	{
		if (filename_flag == 0)
		{
			if (g_buffer.buffer != '\0')
			{
				filename[filename_index++] = g_buffer.buffer;
			}
			else
			{
				filename_flag = 1;
				filename[filename_index] = '\0';
				path = ft_strjoin("./downloads/", filename);
				file_fd = open(path, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0644);
				free(path);
			}
		}
		else if (filesize_flag == 0)
		{
			if (g_buffer.buffer != '\0')
			{
				filesize[filesize_index++] = g_buffer.buffer;
			}
			else
			{
				filesize_flag = 1;
				filesize[filesize_index] = '\0';
				filesize_todownload = ft_atoi(filesize);
				ft_printf("downloading %s (%s bytes)\n", filename, filesize);
			}
		}
		else
		{
			write(file_fd, &g_buffer.buffer, 1);
			downloaded_bytes++;
		}
		if (downloaded_bytes == filesize_todownload && filesize_todownload != 0)
		{
			filename_flag = 0;
			filesize_flag = 0;
			downloaded_bytes = 0;
			filesize_todownload = 0;
			filename_index = 0;
			filesize_index = 0;
			ft_printf("download finished\n");
		}
		g_buffer.buffer = 0;
		g_buffer.size = 0;
	}
	kill(client_pid, SIGUSR1);
}

int main(void)
{
	int pid;
	struct sigaction sa;

	g_buffer.buffer = 0;
	g_buffer.size = 0;
	pid = getpid();
	ft_printf("pid: %d\n", pid);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
