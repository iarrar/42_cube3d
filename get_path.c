/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:18:07 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/29 16:08:25 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_add_path(t_data *data, char **scn)
{
	if (scn == NULL)
		return (1);
	if (ft_strncmp(scn[0], "NO", 2) == 0 && data->path.north_texture == NULL)
		data->path.north_texture = ft_substr(scn[1], 0,
				(ft_search_ext(scn[1], ".xpm") + 4));
	else if (ft_strncmp(scn[0], "SO", 2) == 0
		&& data->path.south_texture == NULL)
		data->path.south_texture = ft_substr(scn[1], 0,
				(ft_search_ext(scn[1], ".xpm") + 4));
	else if (ft_strncmp(scn[0], "WE", 2) == 0
		&& data->path.west_texture == NULL)
		data->path.west_texture = ft_substr(scn[1], 0,
				(ft_search_ext(scn[1], ".xpm") + 4));
	else if (ft_strncmp(scn[0], "EA", 2) == 0
		&& data->path.east_texture == NULL)
		data->path.east_texture = ft_substr(scn[1], 0,
				(ft_search_ext(scn[1], ".xpm") + 4));
	else
	{
		ft_freetabtab(scn);
		return (1);
	}
	ft_freetabtab(scn);
	return (0);
}

int	add_color(t_data *data, char **rgb, char c)
{
	int	r;
	int	g;
	int	b;

	if (rgb[3] != NULL)
		return (1);
	if (!((ft_atoi(rgb[0]) >= 0 && ft_atoi(rgb[0]) <= 255)
			&& (ft_atoi(rgb[1]) >= 0 && ft_atoi(rgb[1]) <= 255)
			&& (ft_atoi(rgb[2]) >= 0 && ft_atoi(rgb[2]) <= 255)))
		return (1);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (c == 'F')
	{
		data->path.ground_color = int_to_hex(1, r, g, b);
	}
	else if (c == 'C')
	{
		data->path.sky_color = int_to_hex(1, r, g, b);
	}
	ft_freetabtab(rgb);
	return (0);
}

int	check_color(t_data *data, char **scn)
{
	if (scn[2] != NULL)
		return (1);
	if (ft_strncmp(scn[0], "F", 1) == 0)
	{
		if (add_color(data, ft_split(scn[1], ','), 'F') == 1)
		{
			ft_freetabtab(scn);
			return (1);
		}
	}
	else if (ft_strncmp(scn[0], "C", 1) == 0)
	{
		if (add_color(data, ft_split(scn[1], ','), 'C') == 1)
		{
			ft_freetabtab(scn);
			return (1);
		}
	}
	ft_freetabtab(scn);
	return (0);
}

int	check_before_add_path(t_data *data, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && (s[i] == 32 || s[i] == ' '))
		i++;
	if (s[i] == '\0')
		return (1);
	else if ((s[i] == 'N' && s[i + 1] == 'O')
		|| (s[i] == 'S' && s[i + 1] == 'O')
		|| (s[i] == 'W' && s[i + 1] == 'E')
		|| (s[i] == 'E' && s[i + 1] == 'A'))
	{
		if (check_add_path(data, ft_split(s, ' ')) == 1)
			return (1);
		return (0);
	}
	else if (s[i] == 'F' || s[i] == 'C')
	{
		if (check_color(data, ft_split(s, ' ')) == 1)
			return (1);
		return (0);
	}
	else
		return (1);
}

int	ft_extract_path(t_data *data)
{
	int	i;

	i = 0;
	init_text(data);
	while (i < 6)
	{
		if (check_if_first_one(data, data->scene[i]) == 0)
			return (1);
		if (check_before_add_path(data, data->scene[i]) == 1)
		{
			printf("\nError: ID for path n.%i isn't valid\n", (i + 1));
			free_path(data);
			return (1);
		}
		i++;
	}
	if (all_path_completed(data) == 1)
	{
		ft_printf("\nError: Not all path are valid\n");
		free_path(data);
		return (1);
	}
	return (0);
}
