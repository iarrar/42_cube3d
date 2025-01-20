/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:24:28 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/29 16:08:41 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_parameter(int argc, char *first_param)
{
	int	i;

	if (argc != 2)
	{
		if (argc < 2)
			write(2, "\nError :\nMap parameter missing\n\n", 32);
		else
			write(2, "\nError :\nToo much arguments\n\n", 29);
		return (1);
	}
	i = 0;
	while (first_param[i] != '\0')
		i++;
	if (first_param[i - 1] != 'b' || first_param[i - 2] != 'u'
		|| first_param[i - 3] != 'c' || first_param[i - 4] != '.')
	{
		write(2, "\nError :\nNot a .cub file\n\n", 26);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	**full_file;

	if (check_parameter(argc, argv[1]) == 1)
		return (1);
	full_file = get_file(argv[1], size_file(argv[1]));
	data.scene = clear_full_file(full_file);
	ft_extract_map(&data);
	if (inv_mp(data.map) || ft_check_walls(data.map) || ft_extract_path(&data))
	{
		ft_freetabtab(full_file);
		ft_freetabtab(data.scene);
		ft_freetabtab(data.map);
		return (1);
	}
	ft_get_coordonate(&data);
	ft_initialisation(&data);
	ft_freetabtab(full_file);
	ft_free_them_all(&data);
	return (0);
}
