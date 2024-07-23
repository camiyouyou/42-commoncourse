NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Imlx -Ilibft -c
RM			= rm -rf
MLXFLAGS	= -Lminilibx-linux -lmlx-Linux -lX11 -lXext

SOURCES		= 
			  ft_printf/aux ft_printf/ft_printf ft_printf/ft_strlen ft_printf/utils \
			  function_lib/sl_split function_lib/sl_strjoin \
			  get_next_line/get_next_line get_next_line/get_next_line_utils \
			  components graphics_management main main_checks utils \ 

OBJECTS     = $(SOURCES:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(MLXFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

all : $(NAME)

re: fclean all

.PHONY: all clean fclean re
