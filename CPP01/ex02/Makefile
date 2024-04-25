NAME = pointersAndRefs
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC_FILES = $(wildcard *.cpp)
OBJ = obj
OBJ_FILES = $(SRC_FILES:%.cpp=$(OBJ)/%.o)

# Color codes for terminal output
PURPLE = \033[1;35m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@printf "The Makefile of [$(PURPLE)POINTERSANDREFS\033[0m] has been compiled! 🧟\n"
	@c++ $(FLAGS) $(OBJ_FILES) -o $(NAME)

${OBJ}/%.o : %.cpp
	@mkdir -p ${OBJ}
	@c++ $(FLAGS) -c $< -o $@
clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all