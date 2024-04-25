NAME = Fixed
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC_FILES = $(wildcard sources/*.cpp)
OBJ = obj
OBJ_FILES = $(SRC_FILES:sources/%.cpp=$(OBJ)/%.o)

# Color codes for terminal output
PURPLE = \033[1;35m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@printf "The Makefile of [$(PURPLE)FIXED\033[0m] has been compiled! 🧟\n"
	@c++ $(FLAGS) -I./ $(OBJ_FILES) -o $(NAME)

${OBJ}/%.o : sources/%.cpp
	@mkdir -p ${OBJ}
	@c++ $(FLAGS) -c $< -o $@
clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

