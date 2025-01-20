/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:46:59 by event             #+#    #+#             */
/*   Updated: 2024/02/29 16:09:42 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_text(t_data *data)
{
	data->path.north_texture = NULL;
	data->path.south_texture = NULL;
	data->path.east_texture = NULL;
	data->path.west_texture = NULL;
	data->path.sky_color = 0;
	data->path.ground_color = 0;
}

int	ft_search_ext(char *str, char *ext)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(&str[i], ext, 4) == 0)
			return (i);
		else
			i++;
	}
	return (0);
}

void	ft_rotate_rev_clockwise(t_data *data)
{
	ft_rotate_dir_rcw(&data->ray.dirx, &data->ray.diry);
	ft_rotate_dir_rcw(&data->ray.planex, &data->ray.planey);
	ft_rotate_rev_clockwise_a(data);
}

void	ft_rotate_clockwise(t_data *data)
{
	ft_rotate_dir_cw(&data->ray.dirx, &data->ray.diry);
	ft_rotate_dir_cw(&data->ray.planex, &data->ray.planey);
	ft_rotate_clockwise_a(data);
}
