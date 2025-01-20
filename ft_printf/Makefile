

NAME = libftprintf.a

SRC = ft_calloc.c ft_bzero.c ft_putchar_fd.c ft_putnbr_fd.c ft_putnbru_uns.c ft_strlen.c ft_adresse.c ft_printf.c ft_putendl_fd.c ft_putnbru_fd.c ft_putstr_fd.c ft_which_sign.c size_base.c ft_countchar.c
OBJ = ${SRC:.c=.o}

LIB = ft_printf.h

FLAGS = -Wall -Werror -Wextra

CC = gcc

all: $(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

.c.o:
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

clean:
	rm -f *.o	

fclean: clean
	rm -f ft_printf.a

re: fclean all
