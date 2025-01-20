/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:14:07 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/29 16:09:20 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_init_value(t_data *data, int x)
{
	data->ray.camerax = 2 * x / (double)WIN_WIDTH - 1;
	data->ray.raydirx = data->ray.dirx + data->ray.planex * data->ray.camerax;
	data->ray.raydiry = data->ray.diry + data->ray.planey * data->ray.camerax;
	data->ray.deltadistx = fabs(1 / data->ray.raydirx);
	data->ray.deltadisty = fabs(1 / data->ray.raydiry);
	data->ray.posx = data->player.x / (float)DIMENSION;
	data->ray.posy = data->player.y / (float)DIMENSION;
	data->ray.mapx = data->ray.posx;
	data->ray.mapy = data->ray.posy;
}

void	raycast_calc_step(t_data *data)
{
	if (data->ray.raydirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.sidedistx = (data->ray.posx - data->ray.mapx)
			* data->ray.deltadistx;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.sidedistx = (data->ray.mapx + 1.0 - data->ray.posx)
			* data->ray.deltadistx;
	}
	if (data->ray.raydiry < 0)
	{
		data->ray.stepy = -1;
		data->ray.sidedisty = (data->ray.posy - data->ray.mapy)
			* data->ray.deltadisty;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.sidedisty = (data->ray.mapy + 1.0 - data->ray.posy)
			* data->ray.deltadisty;
	}
}

void	raycast_mov(t_data *data)
{
	char	hit;

	hit = '0';
	while (hit != '1')
	{
		if (data->ray.sidedistx < data->ray.sidedisty)
		{
			data->ray.sidedistx += data->ray.deltadistx;
			data->ray.mapx += data->ray.stepx;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sidedisty += data->ray.deltadisty;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1;
		}
		hit = data->map[(int)data->ray.mapy][(int)data->ray.mapx];
	}
}

void	raycast_calc_print(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.wall_dist = (data->ray.sidedistx
				- data->ray.deltadistx) + 0.05;
	else
		data->ray.wall_dist = (data->ray.sidedisty
				- data->ray.deltadisty) + 0.05;
	data->ray.lineheight = (int)(WIN_HEIGHT / data->ray.wall_dist);
	data->ray.draw_wall_start = -data->ray.lineheight / 2 + WIN_HEIGHT / 2;
	if (data->ray.draw_wall_start < 0)
		data->ray.draw_wall_start = 0;
	data->ray.draw_wall_end = data->ray.lineheight / 2 + WIN_HEIGHT / 2;
	if (data->ray.draw_wall_end >= WIN_HEIGHT)
		data->ray.draw_wall_end = WIN_HEIGHT - 1;
}

void	raycast_start(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		raycast_init_value(data, x);
		raycast_calc_step(data);
		raycast_mov(data);
		raycast_calc_print(data);
		dray_ray(data, x);
		x++;
	}
}
