/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:13:28 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/29 16:09:24 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	def_wall_touched(t_data *data)
{
	int	x;

	x = 0;
	if (data->ray.side == 0)
	{
		if (data->ray.raydirx > 0)
			x = 3;
		else
			x = 2;
	}
	else
	{
		if (data->ray.raydiry > 0)
			x = 1;
		else
			x = 0;
	}
	return (x);
}

void	init_for_texture(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.wallx = data->ray.posy + data->ray.wall_dist
			* data->ray.raydiry;
	else
		data->ray.wallx = data->ray.posx + data->ray.wall_dist
			* data->ray.raydirx;
	data->ray.wallx -= floor(data->ray.wallx);
	data->ray.texx = (int)(data->ray.wallx * (double)(64));
	data->ray.step = 1.0 * 64 / data->ray.lineheight;
	data->ray.texpos = (data->ray.draw_wall_start - WIN_HEIGHT / 2
			+ data->ray.lineheight / 2) * data->ray.step;
	if ((data->ray.side == 0 && data->ray.raydirx > 0)
		|| (data->ray.side == 1 && data->ray.raydiry < 0))
	{
		data->ray.texx = 64 - data->ray.texx - 1;
	}
}

int	dray_ray2(t_data *data, int x, int i)
{
	if (i < data->ray.draw_wall_start)
	{
		while (i < data->ray.draw_wall_start)
		{
			if (x >= 0 && x < WIN_WIDTH && i >= 0 && i < WIN_HEIGHT)
			{
				data->img.data[i * (data->img.line_len / 4) + x]
					= data->path.sky_color;
			}
			i++;
		}
	}
	else if (i >= data->ray.draw_wall_end)
	{
		while (i <= WIN_HEIGHT)
		{
			if (x >= 0 && x < WIN_WIDTH && i >= 0 && i < WIN_HEIGHT)
			{
				data->img.data[i * (data->img.line_len / 4) + x]
					= data->path.ground_color;
			}
			i++;
		}
	}
	return (i);
}

void	dray_ray(t_data *data, int x)
{
	int	i;
	int	c_wall;

	i = 0;
	data->ray.a = def_wall_touched(data);
	init_for_texture(data);
	while (i <= WIN_HEIGHT)
	{
		if (i == data->ray.draw_wall_start)
		{
			while (i < data->ray.draw_wall_end)
			{
				data->ray.texy = (int)data->ray.texpos & (64 - 1);
				data->ray.texpos += data->ray.step;
				c_wall = data->tx[data->ray.a].data[64 * data->ray.texy
					+ data->ray.texx];
				if (x >= 0 && x < WIN_WIDTH && i >= 0 && i < WIN_HEIGHT)
					data->img.data[i * (data->img.line_len / 4) + x] = c_wall;
				i++;
			}
		}
		else
			i = dray_ray2(data, x, i);
	}
}
