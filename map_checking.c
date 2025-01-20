/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:01:10 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/29 16:08:53 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_width(char **map)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = 0;
	while (map[i] != NULL)
	{
		while (map[i][j])
			j++;
		if (j >= max)
			max = j;
		i++;
	}
	return (max);
}

int	ft_check_contour(char **map, int i, int j)
{
	int	check;
	int	nada;

	nada = 0;
	check = 0;
	if (map[i][j - 1] != 32 && map[i][j - 1] != '1' && map[i][j - 1])
		check ++;
	if (map[i][j + 1] != 32 && map[i][j + 1] != '1' && map[i][j + 1])
		check ++;
	if (j > ft_strlens(map[i + 1]))
		nada++;
	else if (map[i + 1][j] != '\0' && map[i + 1][j]
			!= 32 && map[i + 1][j] != '1')
		check ++;
	if (j > ft_strlens(map[i - 1]))
		nada++;
	else if (map[i - 1][j] != 32 && map[i - 1][j]
			!= '1' && map[i - 1][j])
		check ++;
	return (check);
}

int	ft_check_contour_blank(char **map, int i, int j)
{
	int	check;

	check = 0;
	if (!map[i][j - 1] || map[i][j - 1] == 32)
		check ++;
	if (!map[i][j + 1] || map[i][j + 1] == 32)
		check ++;
	if (map[i + 1] != NULL)
		if (j > ft_strlens(map[i + 1]) || map[i + 1][j] == 32)
			check ++;
	if (map[i - 1] != NULL)
		if (j > ft_strlens(map[i - 1]) || map[i - 1][j] == 32)
			check ++;
	return (check);
}

int	ft_check_inside_map(char **map)
{
	int	i;
	int	j;

	j = 1;
	i = 1;
	while (i < (ft_tabstrlen(map) - 1))
	{
		while (j < (ft_strlens(map[i]) - 1))
		{
			if (inside_map_print(map, i, j) == 1)
				return (1);
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
}

int	ft_check_walls(char **map)
{
	if (ft_check_lr(map) != 0)
	{
		printf("Error lr: Map isn't closed on line %i\n", ft_check_lr(map));
		return (1);
	}
	if (ft_check_ud(map) != 0)
	{
		printf("Error ud: Map isn't closed on line %i\n", ft_check_ud(map));
		return (1);
	}
	else if (ft_check_inside_map(map))
		return (1);
	else
		return (0);
}
