/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:47:09 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/29 16:09:03 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_handle_input(t_data *data)
{
	if (data->espace == 1)
		mlx_loop_end(data->mlx_ptr);
	else if (data->player.rot_right == 1)
		ft_rotate_clockwise(data);
	else if (data->player.rot_left == 1)
		ft_rotate_rev_clockwise(data);
	else if (data->player.mv_up == 1)
		ft_move_up(data);
	else if (data->player.mv_down == 1)
		ft_move_down(data);
	else if (data->player.mv_up == 1)
		ft_move_up(data);
	else if (data->player.mv_down == 1)
		ft_move_down(data);
	else if (data->player.mv_left == 1)
		ft_move_left(data);
	else if (data->player.mv_right == 1)
		ft_move_right(data);
	return ;
}

void	ft_move_up(t_data *data)
{
	double	i;
	double	j;

	j = (data->player.x + (data->player.mvt * data->ray.dirx)) / DIMENSION;
	i = (data->player.y + (data->player.mvt * data->ray.diry)) / DIMENSION;
	if (data->map[(int)i][(int)j] != '1'
		&& data->map[(int)i][(int)j] && data->map[(int)i][(int)j] != 32)
	{
		data->player.x = data->player.x + (data->player.mvt * data->ray.dirx);
		data->player.y = data->player.y + (data->player.mvt * data->ray.diry);
		ft_map_pos(data);
	}
	else
		return ;
}

void	ft_move_down(t_data *data)
{
	double	i;
	double	j;

	j = (data->player.x - (data->player.mvt * data->ray.dirx)) / DIMENSION;
	i = (data->player.y - (data->player.mvt * data->ray.diry)) / DIMENSION;
	if (data->map[(int)i][(int)j] != '1'
		&& data->map[(int)i][(int)j] && data->map[(int)i][(int)j] != 32)
	{
		data->player.x = data->player.x - (data->player.mvt * data->ray.dirx);
		data->player.y = data->player.y - (data->player.mvt * data->ray.diry);
		ft_map_pos(data);
	}
	else
		return ;
}

void	ft_move_left(t_data *data)
{
	double	i;
	double	j;

	j = (data->player.x + (data->player.mvt * data->ray.diry)) / DIMENSION;
	i = (data->player.y - (data->player.mvt * data->ray.dirx)) / DIMENSION;
	if (data->map[(int)i][(int)j] != '1'
		&& data->map[(int)i][(int)j] && data->map[(int)i][(int)j] != 32)
	{
		data->player.x = data->player.x + (data->player.mvt * data->ray.diry);
		data->player.y = data->player.y - (data->player.mvt * data->ray.dirx);
		ft_map_pos(data);
	}
	else
		return ;
}

void	ft_move_right(t_data *data)
{
	double	i;
	double	j;

	j = (data->player.x - (data->player.mvt * data->ray.diry)) / DIMENSION;
	i = (data->player.y + (data->player.mvt * data->ray.dirx)) / DIMENSION;
	if (data->map[(int)i][(int)j] != '1'
		&& data->map[(int)i][(int)j] && data->map[(int)i][(int)j] != 32)
	{
		data->player.x = data->player.x - (data->player.mvt * data->ray.diry);
		data->player.y = data->player.y + (data->player.mvt * data->ray.dirx);
		ft_map_pos(data);
	}
	else
		return ;
}
