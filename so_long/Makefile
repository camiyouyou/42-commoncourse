NAME		= so_long

SOURCES		= ft_printf/aux.c \
		  ft_printf/ft_printf.c \
		  ft_printf/utils.c \
		  function_lib/ft_split.c \
		  function_lib/ft_strjoin.c \
		  function_lib/ft_substr.c \
		  get_next_line/get_next_line.c \
		  get_next_line/get_next_line_utils.c \
		  components.c \
		  algo.c \
		  mem_map.c \
		  graphics_management.c utils.c checks.c \
		  main.c

OBJECTS		= $(SOURCES:%.c=%.o)
RM		= rm -rf
CC		= cc
CFLAGS		= -Wall -Wextra -Werror -Imlx -Ilibft -c
MLXFLAGS	= -Lminilibx-linux -lmlx -lX11 -lXext

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(MLXFLAGS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
