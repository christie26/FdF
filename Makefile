
SRCDIR		= ./src
SRC			= draw_line.c \
			  fdf_utils.c \
			  fdf.c \
			  transform_rotate.c \
			  get_cube.c \
			  get_plan.c \
			  print_center.c \
			  render.c \
			  key_hook.c	
SRC			:= $(addprefix $(SRCDIR)/, $(SRC))
OBJ			= ${SRC:.c=.o}

DYLIB		= ./mlx/libmlx.dylib
NAME		= fdf

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -O3 -ffast-math -g
LDFLAGS		= -fsanitize=address 
RM			= rm -f

all:		${NAME}

%.o: 		%.c $(DYLIB)
			$(CC) $(CFLAGS) $(LDFLAGS) -Imlx -c $< -o $@

$(DYLIB):	
			make -C ./mlx
			cp $(DYLIB) ./

$(NAME): 	$(OBJ) $(DYLIB) libft
			$(CC) $(OBJ) $(LDFLAGS) -L./mlx -lmlx -L./libft -lft -framework OpenGL -framework AppKit -o $(NAME) 

.PHONY:		libft
libft:
			make -j3 -C ./libft all

clean:
			${RM} ${OBJ}
			@make -C ./libft clean
			@make -C ./mlx clean

fclean:		clean
			${RM} ${NAME}
			@make -C ./libft fclean

re:			fclean all

.PHONY:		all clean fclean re
