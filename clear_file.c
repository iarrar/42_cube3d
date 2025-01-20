/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:07:17 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/29 16:07:18 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	line_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != 9)
			return (1);
		i++;
	}
	return (0);
}

int	size_complete_file(char **complete_file)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (complete_file[j] != NULL)
	{
		if (line_empty(complete_file[j]) == 1)
			i++;
		j++;
	}
	return (i);
}

char	**clear_full_file(char **full_file)
{
	char	**clear_file;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = size_complete_file(full_file);
	clear_file = malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		while (line_empty(full_file[j]) != 1)
			j++;
		clear_file[i] = ft_strdup(full_file[j]);
		i++;
		j++;
	}
	clear_file[i] = NULL;
	return (clear_file);
}
