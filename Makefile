NAME					=	fdf
CC						=	cc
FLAGS					=	-Wall -Wextra -Werror -g
RM						=	rm -f

# DIRECTORIES
MLX_DIR = mlx_linux
MLX_LIB	= mlx_Linux

#FILES AND PATH
HEADERS_SRC				=	fdf.h
HEADERS_DIR				=	-I includes/
HEADER					=	$(addprefix $(HEADERS_DIR), $(HEADERS_SRC))

_FDF_FILES				=	main.c read.c map.c env.c hooks.c exit.c \
							image.c isometric.c line.c project_utils.c
FDF_SRC_DIR				=	./sources/
FDF_SRCS				=	$(addprefix $(FDF_SRC_DIR), $(_FDF_FILES))
FDF_OBJS				=	$(FDF_SRCS:.c=.o)

_UTILS_FT				=	ft_bzero.c ft_calloc.c ft_strchr.c ft_abs.c ft_strjoin_secure.c \
							ft_strlen_int.c ft_split.c ft_strdup.c ft_atoi.c ft_swap.c \
							free_utils.c list.c list_tabs.c \
							ft_printf.c ft_print_ptr.c ft_print_unsigned.c ft_simple_utils.c \
							get_next_line.c

UTILS_DIR				=	./utils/
UTILS_FT_SRCS			=	$(addprefix $(UTILS_DIR), $(_UTILS_FT))
UTILS_OBJS				=	$(UTILS_FT_SRCS:.c=.o)


all :	$(NAME)

$(NAME) : $(FDF_OBJS) $(UTILS_OBJS)
	$(CC) $(FLAGS) $(FDF_OBJS) $(UTILS_OBJS) -L$(MLX_DIR) -l $(MLX_LIB) -I $(MLX_DIR) -lXext -lX11 -lm -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -I $(MLX_DIR) -c $< -o $@

clean :
	/bin/$(RM) $(FDF_OBJS)
	/bin/$(RM) $(UTILS_OBJS)

fclean : clean
	/bin/$(RM) -f $(NAME)

re :
	make fclean
	make

re-bonus:
	make fclean
	make bonus

.PHONY: all clean fclean re re-bonus