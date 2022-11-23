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

_UTILS_FT				=	ft_bzero.c ft_calloc.c ft_isnegative.c ft_strchr.c ft_abs.c ft_strjoin_secure.c \
							ft_strlen_int.c ft_split.c ft_strdup.c ft_atoi.c ft_atoi_base.c ft_swap.c \
							free_utils.c list.c list_tabs.c \
							ft_printf.c ft_print_ptr.c ft_print_unsigned.c ft_simple_utils.c \
							get_next_line.c

UTILS_DIR				=	./utils/
UTILS_FT_SRCS			=	$(addprefix $(UTILS_DIR), $(_UTILS_FT))

# MAIN VARIABLES
ALL_SRCS				=	$(FDF_SRCS) $(UTILS_FT_SRCS)
ALL_OBJS				=	$(ALL_SRCS:.c=.o)
ALL_DEPS  				= 	${ALL_SRCS:.c=.d} 

all :	$(NAME)

$(NAME) : $(ALL_OBJS)
	$(CC) $(FLAGS) $(ALL_OBJS) -L$(MLX_DIR) -l $(MLX_LIB) -I $(MLX_DIR) -lXext -lX11 -lm -o $(NAME)

%.o : %.c
	$(CC) -MMD $(FLAGS) -I $(MLX_DIR) -c $< -o $@

clean :
	/bin/$(RM) $(ALL_OBJS)
	/bin/$(RM) $(ALL_DEPS)

fclean : clean
	/bin/$(RM) -f $(NAME)

re :
	make fclean
	make

-include ${ALL_DEPS}

.PHONY: all clean fclean re