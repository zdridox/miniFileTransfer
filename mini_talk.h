/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:28:20 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/29 01:43:47 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include "../libft/libft.h"
# include <signal.h>

typedef struct s_buffer
{
	char					buffer;
	int						size;
}							t_buffer;

typedef struct s_data
{
	char					*message;
	char					*p;
	char					buffer;
	int						buffer_size;
	int						pid;
	int						bytes_size;
	int						bytes_send;
	volatile sig_atomic_t	finished;
}							t_data;

#endif