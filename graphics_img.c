/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:12:38 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/29 16:08:23 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_printscreen(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->img.data = (int *)mlx_get_data_addr(data->img.img_ptr,
			&data->img.bpp, &data->img.line_len, &data->img.endian);
	ft_handle_input(data);
	raycast_start(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	return (0);
}

void	ft_initialisation_data_addr(t_data *data)
{
	data->tx[0].data = (int *)mlx_get_data_addr(data->tx[0].img_ptr,
			&data->tx[0].bpp, &data->tx[0].line_len, &data->tx[0].endian);
	data->tx[1].data = (int *)mlx_get_data_addr(data->tx[1].img_ptr,
			&data->tx[1].bpp, &data->tx[1].line_len, &data->tx[1].endian);
	data->tx[2].data = (int *)mlx_get_data_addr(data->tx[2].img_ptr,
			&data->tx[2].bpp, &data->tx[2].line_len, &data->tx[2].endian);
	data->tx[3].data = (int *)mlx_get_data_addr(data->tx[3].img_ptr,
			&data->tx[3].bpp, &data->tx[3].line_len, &data->tx[3].endian);
}

int	ft_ciao(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	return (0);
}

void	ft_initialisation(t_data *data)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	init_key(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "Cub3d");
	data->tx = malloc(sizeof(t_texture) * 4);
	data->tx[0].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path.north_texture, &width, &height);
	data->tx[1].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path.south_texture, &width, &height);
	data->tx[2].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path.east_texture, &width, &height);
	data->tx[3].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path.west_texture, &width, &height);
	ft_initialisation_data_addr(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_press, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &key_release, data);
	mlx_hook(data->win_ptr, 17, KeyPressMask, &ft_ciao, data);
	mlx_loop_hook(data->mlx_ptr, &ft_printscreen, data);
	mlx_loop(data->mlx_ptr);
	return ;
}
