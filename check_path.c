/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:06:19 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/29 16:07:12 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	inv_mp2(char d)
{
	if (d != 'N' && d != 'S' && d != 'E'
		&& d != 'W' && d != '0' && d != '1' && d != ' ')
	{
		printf("Error : Invalid character on map\n");
		return (1);
	}
	return (0);
}

int	inv_mp(char **m)
{
	int	i;
	int	j;
	int	p;

	i = -1;
	p = 0;
	while (m[++i])
	{
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] == 'N' || m[i][j] == 'S'
				|| m[i][j] == 'W' || m[i][j] == 'E')
				p++;
			if (inv_mp2(m[i][j]) == 1)
				return (1);
			j++;
		}
	}
	if (p != 1)
	{
		printf("Error : Invalid number of player\n");
		return (1);
	}
	return (0);
}

int	check_if_valid_path(t_data *data)
{
	int	fd;

	fd = open(data->path.north_texture, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = 0;
	fd = open(data->path.south_texture, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = 0;
	fd = open(data->path.east_texture, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = 0;
	fd = open(data->path.west_texture, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = 0;
	return (0);
}

int	all_path_completed(t_data *data)
{
	if (data->path.north_texture == NULL)
		return (1);
	else if (data->path.south_texture == NULL)
		return (1);
	else if (data->path.west_texture == NULL)
		return (1);
	else if (data->path.east_texture == NULL)
		return (1);
	else if (data->path.ground_color == 0)
		return (1);
	else if (data->path.sky_color == 0)
		return (1);
	else if (check_if_valid_path(data) == 1)
		return (1);
	return (0);
}
