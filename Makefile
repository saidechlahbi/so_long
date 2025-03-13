CC = cc 
CFLAGS = -Wall -Wextra -Werror

FILES = check_map.c clean.c so_long.c get_map.c get_next_line.c tools.c \
		get_next_line_ulils.c

OBJ = $(FILES:.c=.o)

MAME = so_long

HEADER = so_long.h 

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re