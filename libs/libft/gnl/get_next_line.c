/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:03:11 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/10/17 17:31:54 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_get_line(char *annex_ptr)
{
	char	*line;
	int		index_a;

	index_a = 0;
	if (!annex_ptr || annex_ptr[0] == '\0')
		return (NULL);
	while (annex_ptr[index_a] && annex_ptr[index_a] != '\n')
		index_a++;
	if (annex_ptr[index_a] == '\n')
		index_a++;
	line = (char *)malloc (sizeof(char) * (index_a + 1));
	line = ft_memmove_gnl(line, annex_ptr, (size_t)index_a);
	line[index_a] = '\0';
	return (line);
}

static char	*ft_clean_annex(char *annex_ptr)
{
	char	*sub;
	int		index_a;
	int		index_sub;

	index_a = 0;
	index_sub = 0;
	if (annex_ptr == NULL)
		return (NULL);
	while (annex_ptr[index_a] && annex_ptr[index_a] != '\n')
		index_a++;
	if (annex_ptr[index_a] == '\0')
	{
		free(annex_ptr);
		return (NULL);
	}
	sub = (char *)malloc (sizeof(char)
			* (ft_strlen_gnl(annex_ptr) + 1 - index_a));
	if (sub == NULL)
		return (NULL);
	index_a++;
	while (annex_ptr[index_a])
		sub[index_sub++] = annex_ptr[index_a++];
	sub[index_sub] = '\0';
	free(annex_ptr);
	return (sub);
}

char	*ft_gen_one_line(char **annex_ptr)
{
	char	*line;

	line = ft_get_line(*annex_ptr);
	*annex_ptr = ft_clean_annex(*annex_ptr);
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*annex;
	char		*buffer;
	int			n_read;

	n_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = (char *)malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (!ft_found_new_line(annex) && n_read != 0)
	{
		n_read = (int)read(fd, buffer, BUFFER_SIZE);
		if (n_read == -1)
		{
			free(annex);
			annex = NULL;
			free(buffer);
			return (NULL);
		}
		buffer[n_read] = '\0';
		annex = ft_strjoin_gnl(annex, buffer);
	}
	free (buffer);
	return (ft_gen_one_line(&annex));
}
