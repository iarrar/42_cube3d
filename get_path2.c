/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:08:06 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/29 16:08:08 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	int_to_hex(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

char	*ft_strjoin_char(char *s1, char c)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!dest)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
	}
	if (c != 0)
	{
		dest[i] = c;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	free_path(t_data *data)
{
	free(data->path.south_texture);
	free(data->path.north_texture);
	free(data->path.west_texture);
	free(data->path.east_texture);
}

int	check_if_first_one(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == ' '))
		i++;
	if (str[i] == '1')
	{
		printf("\nError: Not enough path to textures/colors\n");
		free_path(data);
		return (0);
	}
	return (1);
}
