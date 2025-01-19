NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = ../minilibx/libmlx_Linux.a

SRC = main.c utils.c tools.c math.c render.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -lXext -lX11 $(MLX) -o $(NAME)

$(MLX):
	$(MAKE) -C ../minilibx

%.o : %.c fractol.h ../minilibx/mlx.h
	cc -Wall -Wextra -Werror -c $< -o $@
clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ../minilibx clean

re: fclean all