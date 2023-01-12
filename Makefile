
SRCDIR		= ./src
GNLDIR		= ./gnl
SRC			= $(SRCDIR)/draw_line.c \
			  $(SRCDIR)/fdf_utils.c \
			  $(SRCDIR)/main.c \
			  $(SRCDIR)/rotate.c \
			  $(GNLDIR)/get_next_line.c \
			  $(GNLDIR)/get_next_line_utils.c

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
