/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:28:30 by erick             #+#    #+#             */
/*   Updated: 2023/10/17 17:36:06 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	ft_get_map(t_cube *cube)
{
	char	*line;
	char	*tmp;
	int		fd;

	fd = open(cube->path, O_RDONLY);
	if (fd < 0)
		return (close(fd), 0);
	tmp = get_next_line(fd);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = ft_strjoin(tmp, line);
		if (tmp == NULL)
			return (close(fd), free(line), 0);
		free(line);
	}
	close(fd);
	cube->map = ft_split(tmp, '\n');
	free(tmp);
	if (cube->map == NULL)
		return (0);
	return (1);
}