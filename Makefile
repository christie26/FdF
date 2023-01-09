
SRC			= connect_point.c \
			  fdf_utils.c \
			  main.c \
			  main_rotate.c \
###			  draw_cube.c convert.c
OBJ			= ${SRC:.c=.o}
DYLIB		= ./mlx/libmlx.dylib

NAME		= fdf
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

%.o: 		%.c
			$(CC) ${CFLAGS} -Imlx -c $< -o $@

$(DYLIB):	
			@make -C ./mlx
			cp $(DYLIB) .

$(NAME): 	$(OBJ) $(DYLIB)
			$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}
			make clean -C ./mlx

re:			fclean all

.PHONY:		all clean fclean re
