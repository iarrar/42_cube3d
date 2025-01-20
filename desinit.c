/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:27:59 by event             #+#    #+#             */
/*   Updated: 2024/02/29 16:08:30 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_freetabtab(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i] != NULL)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	ft_free_them_all(t_data *data)
{
	int	i;

	i = 0;
	free(data->path.south_texture);
	free(data->path.north_texture);
	free(data->path.west_texture);
	free(data->path.east_texture);
	while (i < 4)
	{
		mlx_destroy_image(data->mlx_ptr, data->tx[i].img_ptr);
		i++;
	}
	ft_freetabtab(data->map);
	free(data->tx);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_freetabtab(data->scene);
}
