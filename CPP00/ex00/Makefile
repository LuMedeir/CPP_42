NAME = megaphone
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC_FILES = $(wildcard *.cpp)
OBJ_FILES = $(SRC_FILES:%.cpp=%.o)

# Color codes for terminal output
PURPLE = \033[1;35m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@printf "The Makefile of [$(PURPLE)MEGAPHONE\033[0m] has been compiled! 🔠\n"
	@c++ $(FLAGS) $(OBJ_FILES) -o $(NAME)
	
%.o : %.cpp
	@c++ $(FLAGS) -c $< -o $@
clean:
	@rm -rf *.o
fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: all
	./$(NAME) "shhhhh... I think the students are asleep..."
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	./$(NAME)