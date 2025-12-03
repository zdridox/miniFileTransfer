/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:04:30 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:04:30 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char const *s, char c)
{
	const char	*p;
	int			word_count;
	int			in_word;

	p = s;
	in_word = 0;
	word_count = 0;
	while (*p != '\0')
	{
		if (*p != c)
			in_word = 1;
		if (*p == c && in_word == 1)
		{
			word_count++;
			in_word = 0;
		}
		p++;
	}
	if (in_word == 1)
		word_count++;
	return (word_count);
}

static void	free_array(char **array, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	**array_allocate(char const *s, char c)
{
	char	**array;
	int		index;
	int		i;

	i = -1;
	index = 0;
	array = malloc((word_counter(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (*s != '\0')
	{
		if (*s != c)
			i++;
		if ((*s == c && i != -1) || (*(s + 1) == '\0' && i != -1))
		{
			array[index] = malloc(i + 2);
			if (!array[index++])
				return (free_array(array, index - 1), NULL);
			i = -1;
		}
		s++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		index;
	int		i;

	i = -1;
	index = 0;
	if (!s)
		return (NULL);
	array = array_allocate(s, c);
	if (array == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s != c)
		{
			array[index][i++ + 1] = *s;
		}
		if ((*s == c && i != -1) || (*(s + 1) == '\0' && i != -1))
		{
			array[index++][i + 1] = '\0';
			i = -1;
		}
		s++;
	}
	return (array[index] = NULL, array);
}
