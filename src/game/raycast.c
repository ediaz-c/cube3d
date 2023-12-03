/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:43:24 by erick             #+#    #+#             */
/*   Updated: 2023/12/01 16:06:15 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
/*
*	First operation of raycasting
*	1. Calculate camera_x
*	2. Calculate ray_dir and delta_dist
*	3. Calculate step and side_dist
*/
void	ft_first_op(t_cube *cube, t_player *p, t_raysult *ray, int x)
{
	ray->mpos.x = (int)p->pos.x;
	ray->mpos.y = (int)p->pos.y;
	ray->hit = 0;
	ft_calculate_ray_and_dist(cube, ray, p, x);
	ft_calculate_step(cube, ray, p);
}

void	raycasting(t_cube *cube)
{
	int			x;
	t_raysult	ray;
	t_line		line;
	t_player	*player;

	x = -1;
	player = cube->p;
	mlx_clear_window(cube->mlx->mlx, cube->mlx->win);
	while (++x < WIN_W)
	{
		ft_first_op(cube, player, &ray, x);
		line.wall_tex = ft_dda(cube, &ray, player);
		ft_calculate_wall_dist(&ray, player);
		ft_caltulate_line(cube, &line, &ray);
		ft_calculate_texture_x(cube, &line, &ray, x);
		ft_paint_pixels(cube, &line, &ray, x);
	}
}
