# NAME = Array
# FLAGS = -Wall -Wextra -Werror -std=c++98
# SRC_FILES = $(wildcard sources/*.cpp)
# OBJ = obj
# OBJ_FILES = $(SRC_FILES:sources/%.cpp=$(OBJ)/%.o)

# # Color codes for terminal output
# PURPLE = \033[1;35m

# all: $(NAME)

# $(NAME): $(OBJ_FILES)
# 	@printf "The Makefile of [$(PURPLE)ARRAY\033[0m] has been compiled!\n"
# 	@c++ $(FLAGS) -I./ $(OBJ_FILES) -o $(NAME)

# ${OBJ}/%.o : sources/%.cpp
# 	@mkdir -p ${OBJ}
# 	@c++ $(FLAGS) -c $< -o $@

# leak:
# 	valgrind --leak-check=full -q ./$(NAME)
# clean:
# 	@rm -rf $(OBJ)

# fclean: clean
# 	@rm -rf $(NAME)

# re: fclean all

TARGET=Array.exec
ECHO=/usr/bin/echo -e
YELLOW=\033[1;33m
GREEN=\033[1;32m
RESET=\033[0m

MANDATORY_FLAGS=-Wall -Wextra -Werror --std=c++98 -g3

SOURCES=${wildcard sources/*.cpp}
INCLUDE=${wildcard includes/*.hpp}
EXTRA_DEPS=${wildcard sources/*.tpp} ${wildcard include/*.tpp}

${TARGET}: ${INCLUDE} ${EXTRA_DEPS} ${SOURCES}
	@${ECHO} "${YELLOW}Compiling $@...${RESET}"
	@c++ ${MANDATORY_FLAGS} -Iinclude ${SOURCES} -o $@
	@${ECHO} "${GREEN}Done!${RESET}"

fclean:
	@rm -fr ${TARGET}
	@${ECHO} "${GREEN}Executable removed!${RESET}"
.PHONY: fclean

re: fclean ${TARGET}
.PHONY: re