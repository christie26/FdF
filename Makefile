
SRCDIR		= ./src
SRC			= draw_line.c \
			  fdf_utils.c \
			  main.c \
			  rotate.c \
			  map_valid.c \
			  print_center.c
SRC			:= $(addprefix $(SRCDIR)/, $(SRC))
OBJ			= ${SRC:.c=.o}

DYLIB		= ./mlx/libmlx.dylib
NAME		= fdf

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -O3 -ffast-math
RM			= rm -f

all:		${NAME}

%.o: 		%.c
			$(CC) ${CFLAGS} -c $< -o $@

$(DYLIB):	
			@make -C ./mlx
			cp $(DYLIB) .

$(NAME): 	$(OBJ) $(DYLIB) libft
			$(CC) $(OBJ) -L./mlx -lmlx -L./libft -lft -framework OpenGL -framework AppKit -o $(NAME) 

.PHONY:		libft
libft:
			@make -j3 -C ./libft all

clean:
			${RM} ${OBJ}
			@make -C ./libft clean
			@make -C ./mlx clean

fclean:		clean
			${RM} ${NAME}
			@make -C ./libft fclean

re:			fclean all

.PHONY:		all clean fclean re
