CC = cc 
CFLAGS = -Wall -Wextra -Werror

FRAMEWORKS = -L/usr/include/minilibx-linux -lmlx -lX11 -lXext -lm

FILES = check_map.c clean.c so_long.c get_map.c get_next_line.c tools.c \
		get_next_line_ulils.c

OBJ = $(FILES:.c=.o)


NAME = so_long

HEADER = so_long.h 

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) $(FRAMEWORKS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re