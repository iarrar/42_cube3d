/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:07:55 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/29 16:07:56 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	size_file(char *file_name)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	free(str);
	close(fd);
	return (i);
}

char	*transf_lastn(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			map[i] = '\0';
		i++;
	}
	return (map);
}

char	**get_file(char *file_name, int size)
{
	int		fd;
	int		i;
	int		size2;
	char	**complete_file;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	size2 = size_file(file_name);
	complete_file = malloc(sizeof(char *) * (size + 1));
	while (i <= size2 - 1)
	{
		complete_file[i] = get_next_line(fd);
		complete_file[i] = transf_lastn(complete_file[i]);
		i++;
	}
	complete_file[i] = NULL;
	close(fd);
	return (complete_file);
}
