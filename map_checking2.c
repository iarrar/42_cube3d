/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:08:56 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/29 16:08:57 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_tabstrlen(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	else
	{
		while (map[i] != NULL)
			i++;
		return (i);
	}
}

int	ft_check_ud(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = ft_tabstrlen(map) - 1;
	while (map[0][i])
	{
		if (map[0][i] == 32 || map[0][i] == '1')
			i++;
		else
			return (1);
	}
	i = 0;
	while (map[j][i])
	{
		if (map[j][i] == 32 || map[j][i] == '1')
			i++;
		else
			return (j);
	}
	return (0);
}

int	ft_check_lr(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] == 32 || map[i][0] == '1')
			i++;
		else
			return (1);
	}
	i = 0;
	while (map[i] != NULL)
	{
		j = ft_strlens(map[i]) - 1;
		if (map[i][j] == 32 || map[i][j] == '1')
			i++;
		else
			return (1);
	}
	return (0);
}

int	inside_map_print(char **map, int i, int j)
{
	if (map[i][j] == 32)
	{
		if (ft_check_contour(map, i, j))
		{
			ft_printf("\nError: Space at forbiden place : %i, %i\n", i, j);
			return (1);
		}
	}
	else if (map[i][j] == '0')
	{
		if (ft_check_contour_blank(map, i, j))
		{
			ft_printf("\nError: Missing wall around 0 : %i, %i\n", i, j);
			return (1);
		}
	}
	else if (is_it_a_player(map, i, j))
	{
		if (ft_check_contour_blank(map, i, j) && map[i][j] != '1')
		{
			ft_printf("\nError: Missing wall around player: %i, %i\n", i, j);
			return (1);
		}
	}
	return (0);
}

int	is_it_a_player(char **map, int i, int j)
{
	if (map[i][j] == 'N')
		return (1);
	else if (map[i][j] == 'S')
		return (1);
	else if (map[i][j] == 'W')
		return (1);
	else if (map[i][j] == 'E')
		return (1);
	else if (map[i][j] == '1')
		return (1);
	else
	{
		printf("\nError : Unknown item at (%i, %i)\n", i, j);
		return (0);
	}
}
