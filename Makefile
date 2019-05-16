##
## EPITECH PROJECT, 2019
## navy
## File description:
## Makefile
##

NAME	= navy

CC	= gcc

RM	= rm -f

SRCS	= ./src/get_next_line/get_next_line.c		\
	  ./src/main.c					\
	  ./src/communication/wait_for_connect.c	\
	  ./src/communication/pass_coord.c		\
	  ./src/communication/pass_hit.c		\
	  ./src/map_loading/create_map.c		\
	  ./src/map_loading/load.c			\
	  ./src/map_loading/write_map.c			\
	  ./src/utils/my_atoi.c				\
	  ./src/utils/my_put_nbr.c			\
	  ./src/utils/my_putstr.c			\
	  ./src/utils/alpha.c				\
	  ./src/utils/my_strlen.c			\
	  ./src/game_loop/check_entry.c			\
	  ./src/game_loop/map.c				\
	  ./src/game_loop/is_hit.c			\
	  ./src/game_loop/game_loop.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
