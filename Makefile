SRC		=	main.c				\
			close.c				\
			key_handler.c		\
			load/enemy.c		\
			load/hitbox.c		\
			load/img.c			\
			load/player.c		\
			load/scene.c		\
			load/souls.c		\
			render/animate.c	\
			render/bg.c			\
			render/enemy.c		\
			render/img.c		\
			render/pixel.c		\
			render/render.c		\
			render/scene.c		\
			update/enemy.c		\
			update/input.c		\
			update/player.c		\
			update/ply_action.c	\
			update/update.c		\

SRC		:=	$(addprefix src/, $(SRC))

OBJ_DIR	=	obj/
OBJ		=	$(patsubst src/%.c,$(OBJ_DIR)%.o,$(SRC))

INCLUDE	=	-I./include/

MLX_INCLUDE	=	-Imlx

UNAME := $(shell uname -s)

MINILIB	=	libmlx_Linux.a
LIB		=	-L./.lib -lft -L./.mlx -lmlx_Linux -lXext -lX11 -lbsd -lm
CC		=	clang -o $(NAME) $(MLX_INCLUDE) $(INCLUDE) $(OBJ) $(LIB) $(FLAG)

FLAG	=	-Wall -Wextra -Werror -g3

NAME	=	so_long

DEFAULT	=	\033[0m
GREEN	=	\033[0;32m
RED		=	\033[0;31m
YELLOW	=	\033[0;33m
CYAN	=	\033[0;36m
BOLD	=	\033[1m

$(OBJ_DIR)%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)load
	@mkdir -p $(OBJ_DIR)render
	@mkdir -p $(OBJ_DIR)update
	@echo "$(CYAN)Compiling:$(DEFAULT) $<"
	@clang $(INCLUDE) $(MLX_INCLUDE) $(FLAG) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
	@if [ ! -e ./.mlx/libmlx_Linux.a ]; then \
		echo "$(YELLOW)$(BOLD)Creating:$(DEFAULT) libmlx";	\
		make -C .mlx/ --quiet;	\
		echo "$(GREEN)$(BOLD)Done$(DEFAULT)";	\
	fi
	@if [ ! -e ./.lib/libft.a ]; then \
		echo "$(YELLOW)$(BOLD)Creating:$(DEFAULT) libft";	\
		make -C .lib/ --quiet;	\
		echo "$(GREEN)$(BOLD)Done$(DEFAULT)";	\
	fi
	@echo "$(YELLOW)$(BOLD)Creating:$(DEFAULT) ./$(NAME)"
	@$(CC)
	@echo "$(GREEN)$(BOLD)Done$(DEFAULT)"

clean:
	@echo "$(RED)Cleaning:$(DEFAULT) $(OBJ)"
	@make clean -C .lib/ --quiet
	@rm -rf $(OBJ_DIR)
	@rm -f $(MAINOBJ)
	@echo "$(GREEN)Done:$(DEFAULT) $(OBJ)"

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C .lib/ --quiet
	@rm -f code

lib-clean:
	@echo "$(RED)Cleaning lib...$(DEFAULT)"
	@make fclean -C .lib --quiet
	@rm -rf ./.mlx/*.a
	@echo "$(GREEN)Done.$(DEFAULT)"

re:	fclean all

.PHONY: all clean fclean libclean re
