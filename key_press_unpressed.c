/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_unpressed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:08:19 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/29 16:08:20 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		data->espace = 1;
	else if (keysym == XK_Right)
		data->player.rot_right = 1;
	else if (keysym == XK_Left)
		data->player.rot_left = 1;
	else if (keysym == XK_Up)
		data->player.mv_up = 1;
	else if (keysym == XK_Down)
		data->player.mv_down = 1;
	else if (keysym == XK_w)
		data->player.mv_up = 1;
	else if (keysym == XK_s)
		data->player.mv_down = 1;
	else if (keysym == XK_a)
		data->player.mv_left = 1;
	else if (keysym == XK_d)
		data->player.mv_right = 1;
	else if (keysym == XK_Shift_L)
		data->player.mvt = 6.5;
	return (0);
}

int	key_release(int keysym, t_data *data)
{
	if (keysym == XK_Right)
		data->player.rot_right = 0;
	else if (keysym == XK_Left)
		data->player.rot_left = 0;
	else if (keysym == XK_Up)
		data->player.mv_up = 0;
	else if (keysym == XK_Down)
		data->player.mv_down = 0;
	else if (keysym == XK_w)
		data->player.mv_up = 0;
	else if (keysym == XK_s)
		data->player.mv_down = 0;
	else if (keysym == XK_a)
		data->player.mv_left = 0;
	else if (keysym == XK_d)
		data->player.mv_right = 0;
	else if (keysym == XK_Shift_L)
		data->player.mvt = 3.25;
	return (0);
}

void	init_key(t_data *data)
{
	data->espace = 0;
	data->player.rot_right = 0;
	data->player.rot_left = 0;
	data->player.mv_up = 0;
	data->player.mv_down = 0;
	data->player.mv_left = 0;
	data->player.mv_right = 0;
}
