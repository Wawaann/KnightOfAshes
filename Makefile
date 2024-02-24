SRC	=	src/main.cpp			\
		src/event.cpp			\
		src/mapManager.cpp		\
		src/background.cpp		\
		src/camera.cpp			\
		src/player.cpp			\

OBJ	=	$(SRC:.cpp=.o)

NAME	=	KnightOfAshes

CXXFLAGS	=	-std=c++17 -g3

LDFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

BLUE	=	\e[34m
BOLD	=	\e[1m
CYAN	=	\e[36m
DEFAULT	=	\e[0m
GREEN	=	\e[32m
MAGEN	=	\e[35m
RED		=	\e[31m

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e "$(BOLD)$(BLUE)Compiling $(NAME)...$(DEFAULT)"
	@g++ -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo -e "$(BOLD)$(GREEN)$(NAME) compiled successfully!$(DEFAULT)"

clean:
	@echo -e "$(BOLD)$(RED)Cleaning object files...$(DEFAULT)"
	@rm -f $(OBJ)
	@echo -e "$(BOLD)$(GREEN)Object files cleaned successfully!$(DEFAULT)"

fclean:	clean
	@echo -e "$(BOLD)$(RED)Cleaning $(NAME)...$(DEFAULT)"
	@rm -f $(NAME)
	@echo -e "$(BOLD)$(GREEN)$(NAME) cleaned successfully!$(DEFAULT)"

re:	fclean all
