NAME = solong

FLAGS = -Wall -Wextra -Werror
SRC = ./src/solong.c \
	./src/ft_utils.c \
	./src/ft_utils1.c \
	./src/get_map.c \
	./src/check_arg.c \
	./src/check_map.c \
	./src/check_map1.c \
	./src/write_map.c \
	./src/game.c \
	./src/key_manager.c \
	./src/free_map.c \
	./src/move.c \
	

RM = rm -rf

all:
	gcc -Wall -Wextra -Werror $(FLAGS) $(SRC) -framework OpenGL -framework AppKit -o $(NAME) "./minilibx/libmlx.a"

clean:
	rm -f $(NAME)
fclean: clean
re: fclean all