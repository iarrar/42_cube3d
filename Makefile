
NAME = cub3d

#LIB = solong.h

FLAGS = -Wall -Wextra -Werror -g

LIB_FLAGS = -lm -lXext -lX11

GNLSRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

LIBFT = ./libft/libft.a

FTPRINTF = ./ft_printf/libftprintf.a

MINILIB = ./minilibx-linux/libmlx_Linux.a ./minilibx-linux/libmlx.a

SRCS = main.c parsing.c raycast.c raycast2.c desinit.c rotation.c map_checking.c player_data.c mouvements.c graphics_img.c check_path.c clear_file.c get_file.c get_path.c utils.c get_path2.c map_checking2.c key_press_unpressed.c
CC = gcc

all: $(NAME)

$(NAME):	
	make -C ./minilibx-linux
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) $(GNLSRC) $(MINILIB) $(FTPRINTF) -o $(NAME) $(LIB_FLAGS)
	
clean:
	rm -f *.o
	make clean -C ./libft
	make clean -C ./ft_printf
	make clean -C ./minilibx-linux

fclean: clean
	rm $(NAME)

re: fclean all

rere:
	rm -f *.o
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) $(FTPRINTF) $(MINILIB) $(LIB_FLAGS) -o $(NAME)

