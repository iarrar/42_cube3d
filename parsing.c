/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:54:42 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/29 16:09:07 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(char *str)
{
	if (ft_strlen(str) < 4)
	{
		ft_putstr_fd("File extension non valide\n", 2);
		return (0);
	}
	if (ft_strncmp(".cub", &str[ft_strlen(str) - 4], 4))
	{
		ft_putstr_fd("File extension non valide\n", 2);
		return (0);
	}
	else
		return (1);
}

int	ft_search_line(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
	{
		if (ft_is_alnum(tab[i]))
			return (i);
		else
			i++;
	}
	return (0);
}

int	ft_is_alnum(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	else
	{
		while (str[i] && (str[i] == 32 || (str[i] >= '0' && str[i] <= '9')))
			i++;
		if (i == ft_strlens(str))
			return (1);
		else
			return (0);
	}
}

char	**tabtab_substr(t_data *data)
{
	int		i;
	int		j;
	char	**dest;

	j = ft_search_line(data->scene);
	i = 0;
	while (data->scene[i] != NULL)
		i++;
	dest = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (data->scene[i + j] != NULL)
	{
		dest[i] = ft_strdup(data->scene[j + i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

void	ft_extract_map(t_data *data)
{
	data->map = tabtab_substr(data);
	return ;
}
