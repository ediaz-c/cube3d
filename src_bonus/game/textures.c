/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:28:09 by erick             #+#    #+#             */
/*   Updated: 2023/12/08 14:04:08 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_img	*ft_get_img_cube(t_cube *cube)
{
	cube->img.img = (int *)mlx_new_image(cube->mlx->mlx, WIN_W, WIN_H);
	if (cube->img.img == NULL)
		return (NULL);
	cube->img.buffer = (int *)mlx_get_data_addr(cube->img.img,
		&cube->img.bpp, &cube->img.size_line, &cube->img.endian);
	if (cube->img.buffer == NULL)
		return (NULL);
	return (&cube->img);
}

t_img	*ft_create_img(t_img *img, char *path, t_mlx *mlx)
{
	img->img = mlx_xpm_file_to_image(mlx->mlx, path, &img->width, &img->height);
	if (img->img == NULL)
		return (NULL);
	img->buffer = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_line, &img->endian);
	if (img->buffer == NULL)
		return (NULL);
	return (img);
}

int	ft_init_textures(t_cube *cube)
{
	cube->txt = malloc(sizeof(t_texture));
	if (cube->txt == NULL)
		return (EXIT_FAILURE);
	if (ft_create_img(&cube->txt->no, cube->no, cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_create_img(&cube->txt->so, cube->so, cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_create_img(&cube->txt->ea, cube->we, cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_create_img(&cube->txt->we, cube->ea, cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_create_img(&cube->txt->door, "./textures/extra/door.xpm", cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_create_img(&cube->txt->door_wall, "./textures/extra/door_wall.xpm", cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_create_img(&cube->txt->ceiling, "./textures/extra/ceiling.xpm", cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_create_img(&cube->txt->floor, "./textures/extra/floor.xpm", cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_get_img_cube(cube) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
