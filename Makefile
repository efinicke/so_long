
NAME                    =       so_long
MLX_DIR                 =       ./mlx/
SRC_DIR                 =       ./srcs/
INC_DIR                 =       ./inc/
SRCS                    =       00_main.c \
                                        01_file_parsing.c \
                                        02_map_extraction.c \
                                        03_map_parsing.c \
                                        03_map_parsing2.c \
                                        04_draw_map_on_window.c \
                                        05_player_moves.c \
                                        06_free_all.c \
										07_utils.c \

SRC_BASENAME			=       $(addprefix $(SRC_DIR), $(SRCS))
OBJS					=		$(SRC_BASENAME:.c=.o)
CC						=		gcc
FLAGS					=		-Wall -Wextra -Werror -I $(MLX_DIR) -I $(INC_DIR)

.c.o			:
						$(CC) $(FLAGS) -Imlx -c $< -o $@

all				:		$(NAME)

$(NAME)			:		$(OBJS)
						make -C $(MLX_DIR)
						$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L $(MLX_DIR) -ldl -Imlx -Lmlx -lmlx -lm -lXext -lX11
						@echo "$(NAME) created !"

clean			:
						rm -rf $(OBJS)
						make clean -C $(MLX_DIR)
						@echo "objects deleted"

fclean			:		clean
						rm -f $(NAME)
						@echo "$(NAME) deleted"

re		:		fclean all