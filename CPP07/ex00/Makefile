NAME = Template
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC_FILES = $(wildcard sources/*.cpp)
OBJ = obj
OBJ_FILES = $(SRC_FILES:sources/%.cpp=$(OBJ)/%.o)

# Color codes for terminal output
PURPLE = \033[1;35m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@printf "The Makefile of [$(PURPLE)TEMPLATE\033[0m] has been compiled!\n"
	@c++ $(FLAGS) -I./ $(OBJ_FILES) -o $(NAME)

${OBJ}/%.o : sources/%.cpp
	@mkdir -p ${OBJ}
	@c++ $(FLAGS) -c $< -o $@

leak:
	valgrind --leak-check=full -q ./$(NAME)
clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
