/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:24:41 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/29 16:07:45 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define GREEN 0x00FF00
# define RED 0xFF0000
# define WHITE 0xFFFFFF
# define BLUE 0x0000FF
# define PI 3.141592
# define DIMENSION 64

typedef struct s_texture
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		line_len;
	int		endian;
	double	text_pos;
}	t_texture;

typedef struct s_imge
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		line_len;
	int		endian;
}	t_imge;

typedef struct s_path
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		ground_color;
	int		sky_color;
}	t_path;

typedef struct s_player
{
	double	x;
	double	y;
	int		mx;
	int		my;
	int		dist;
	double	a;
	int		mvt;
	int		mv_left;
	int		mv_right;
	int		mv_up;
	int		mv_down;
	int		rot_right;
	int		rot_left;
}	t_player;

typedef struct s_item
{
	int		posx;
	int		posy;
	int		posmapx;
	int		posmapy;
	double	angle;
	char	type;
	int		mvt;
	int		color;
	t_imge	sprite;
}	t_item;

typedef struct s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		planex;
	double		planey;
	double		camerax;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	double		wall_dist;
	int			side;
	int			lineheight;
	int			draw_wall_start;
	int			draw_wall_end;
	int			texy;
	int			a;
	int			texx;
	double		step;
	double		texpos;
	double		wallx;
}	t_ray;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	player;
	t_item		exit;
	t_item		exit_close;
	t_item		exit_open;
	t_item		wall;
	t_item		font;
	t_item		cookie;
	t_ray		ray;
	t_imge		img;
	t_texture	*tx;
	t_texture	texture_north;
	t_path		path;
	char		*str;
	char		**map;
	char		**scene;
	int			count;
	int			dimension;
	int			map_height;
	int			map_width;
	int			win_height;
	int			win_width;
	int			e;
	int			p;
	int			r;
	int			espace;
}	t_data;

int			check_extension(char *str);
int			get_data(char *str, t_data *data);
int			ft_is_alnum(char *str);
char		**tabtab_substr(t_data *data);
void		ft_extract_map(t_data *data);
int			ft_check_walls(char **map);
int			ft_tabstrlen(char **map);
int			ft_check_ud(char **map);
int			ft_check_lr(char **map);
int			ft_width(char **map);
int			ft_check_contour(char **map, int i, int j);
int			ft_check_inside_map(char **map);
void		ft_get_coordonate(t_data *data);
void		ft_initialisation(t_data *data);
void		ft_handle_input(t_data *data);
void		ft_free_them_all(t_data *data);
void		img_pix_put(t_imge *img, int x, int y, int color);
int			render_rect(t_imge *img, t_item rect);
void		render_background(t_imge *img, int color);
int			render(t_data *data);
void		ft_create_img(t_data *data);
void		ft_map_pos(t_data *data);
int			pos(t_data *data, int i, int j, double a);
void		ft_init_dir(t_data *data, double a);
void		ft_init_plane(t_data *data, double a);
int			ft_max(int a, int b);
void		raycast_start(t_data *data);
void		ft_rotate_clockwise(t_data *data);
void		ft_rotate_rev_clockwise(t_data *data);
void		ft_move_up(t_data *data);
void		ft_move_down(t_data *data);
void		ft_move_left(t_data *data);
void		ft_move_right(t_data *data);
void		ft_rotate_dir_cw(double *x, double *y);
void		ft_rotate_dir_rcw(double *x, double *y);
void		ft_rotate_clockwise_a(t_data *data);
void		ft_rotate_rev_clockwise_a(t_data *data);
int			check_parameter(int argc, char *first_param);
char		**get_file(char *file_name, int size);
int			size_file(char *file_name);
char		**clear_full_file(char **full_file);
int			size_file(char *file_name);
int			ft_extract_path(t_data *data);
int			all_path_completed(t_data *data);
void		dray_ray(t_data *data, int x);
int			ft_search_ext(char *str, char *ext);
void		ft_freetabtab(char **map);
int			check_if_first_one(t_data *data, char *str);
char		*ft_strjoin_char(char *s1, char c);
int			int_to_hex(int t, int r, int g, int b);
int			inside_map_print(char **map, int i, int j);
int			ft_check_contour_blank(char **map, int i, int j);
int			key_press(int keycode, t_data *data);
int			key_release(int keycode, t_data *data);
void		init_key(t_data *data);
void		free_path(t_data *data);
void		init_text(t_data *data);
int			inv_mp(char **m);
int			is_it_a_player(char **map, int i, int j);

#endif