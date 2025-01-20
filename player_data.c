/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:52:23 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/29 16:09:15 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_coordonate(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' && !pos(data, i, j, (PI / 2)))
				return ;
			else if (data->map[i][j] == 'E' && pos(data, i, j, 0) == 0)
				return ;
			else if (data->map[i][j] == 'W' && pos(data, i, j, PI) == 0)
				return ;
			else if (data->map[i][j] == 'S' && !pos(data, i, j, ((3 * PI) / 2)))
				return ;
			else
				j++;
		}
		j = 0;
		i++;
	}
	printf("Error\nNo player found on the map\n");
	return ;
}

int	pos(t_data *data, int i, int j, double a)
{
	data->player.mx = j;
	data->player.my = i;
	data->player.x = j * DIMENSION;
	data->player.y = i * DIMENSION;
	data->player.mvt = 3.25;
	data->player.dist = 0;
	data->player.a = a;
	ft_init_dir(data, a);
	ft_init_plane(data, a);
	return (0);
}

void	ft_init_dir(t_data *data, double a)
{
	if (a == 0)
	{
		data->ray.dirx = 1;
		data->ray.diry = 0;
	}
	else if (a == (PI / 2))
	{
		data->ray.dirx = 0;
		data->ray.diry = -1;
	}
	else if (a == PI)
	{
		data->ray.dirx = -1;
		data->ray.diry = 0;
	}
	else if (a == ((3 * PI) / 2))
	{
		data->ray.dirx = 0;
		data->ray.diry = 1;
	}
	else
		printf("Wrong Direction\n");
}

void	ft_init_plane(t_data *data, double a)
{
	if (a == 0)
	{
		data->ray.planex = 0;
		data->ray.planey = 0.90;
	}
	else if (a == (PI / 2))
	{
		data->ray.planex = 0.90;
		data->ray.planey = 0;
	}
	else if (a == PI)
	{
		data->ray.planex = 0;
		data->ray.planey = -0.90;
	}
	else if (a == ((3 * PI) / 2))
	{
		data->ray.planex = -0.90;
		data->ray.planey = 0;
	}
	else
		printf("Wrong Direction\n");
}

void	ft_map_pos(t_data *data)
{
	data->player.mx = (data->player.x / DIMENSION);
	data->player.my = (data->player.y / DIMENSION);
}
