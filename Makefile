
SRC			= video.c
OBJ			= ${SRC:.c=.o}

NAME		= fdf
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

%.o: 		%.c
			$(CC) ${CFLAGS} -Imlx -c $< -o $@

$(NAME): 	$(OBJ)
			$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			${RM} ${OBJ}
			make clean -C ./mlx

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
