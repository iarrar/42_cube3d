/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:28:38 by event             #+#    #+#             */
/*   Updated: 2024/02/29 16:09:28 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate_clockwise_a(t_data *data)
{
	data->player.a -= 0.09;
	if (data->player.a < 0)
		data->player.a += (2 * PI);
}

void	ft_rotate_rev_clockwise_a(t_data *data)
{
	data->player.a += 0.09;
	if (data->player.a >= (2 * PI))
		data->player.a -= (2 * PI);
}

void	ft_rotate_dir_cw(double *x, double *y)
{
	double	new_x;
	double	new_y;

	new_x = (*x) * cos(0.09) - (*y) * sin(0.09);
	new_y = (*x) * sin(0.09) + (*y) * cos(0.09);
	*x = new_x;
	*y = new_y;
}

void	ft_rotate_dir_rcw(double *x, double *y)
{
	double	new_x;
	double	new_y;

	new_x = (*x) * cos(0.09) - (-1 * (*y) * sin(0.09));
	new_y = -(*x) * sin(0.09) + (1 * (*y) * cos(0.09));
	*x = new_x;
	*y = new_y;
}
