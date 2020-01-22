##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC        =    gcc

SRC     =	src/matchstick.c				\
			src/tools_functions.c			\
			src/map.c						\
			src/draw.c						\
			src/victory.c					\
			src/error.c						\
			src/update_game.c				\
			src/ai.c						\

OBJ     =	$(SRC:.c=.o) 			\

COVERAGE		=	$(SRC:.c=.gcda)				\
					$(MAIN_SRC:.c=.gcda)		\
					$(TEST_SRC:.c=.gcda)		\
					$(SRC:.c=.gcno)				\
					$(MAIN_SRC:.c=.gcno)		\
					$(TEST_SRC:.c=.gcno)		\

MAIN_SRC    =    src/main.c			\

MAIN_OBJ    =    $(MAIN_SRC:.c=.o)	\

CFLAGS    =    -I./include -Wextra -g3

TARGET    =		matchstick		\

TEST_SRC     =     tests/criterion.c		\

TEST_OBJ     =     $(TEST_SRC:.c=.o)

TEST_TARGET     =     unit_tests

LDFLAGS     =     -lcriterion -lgcov

all: $(TARGET) ## Build the project

$(TARGET): build

build: $(OBJ) $(MAIN_OBJ) ## Compile the project
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished compiling sources ▄▀▄▀▄▀\e[0m\n"
	@$(CC) $(CFLAGS) $(OBJ) $(MAIN_OBJ) -o $(TARGET)
	@printf "[\e[1;34m-Link Obj-\e[0m] % 43s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;34m-Link Main-\e[0m] % 43s\n" $(MAIN_OBJ) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Link all object ▄▀▄▀▄▀\e[0m\n"

%.o : %.c
	@$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34m-Compiled-\e[0m] % 41s\n" $@ | tr ' ' '.'

clean: ## Clean the useless file
	@rm -f $(OBJ) $(MAIN_OBJ) $(TEST_OBJ) $(COVERAGE)

fclean: clean ## Clean the project
	@rm -f $(TARGET) $(TEST_TARGET)
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(TARGET) | tr ' ' '.'
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(TEST_TARGET) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished RM ▄▀▄▀▄▀\e[0m\n"

re:    fclean all ## Clean then compile

tests_build: $(OBJ) $(TEST_OBJ) ## Build tests
	@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(TEST_OBJ) -o $(TEST_TARGET)

tests_run: ## Launch tests
	@$(CC) -o unit_tests $(LDFLAGS) $(SRC) $(TEST_SRC) $(CFLAGS)
	@./$(TEST_TARGET)
	@gcovr --exclude tests/

re_tests: fclean tests_run ## Clean then tests

valgrind: all ## Launch valgrind
	@valgrind --track-origins=yes --show-leak-kinds=all ./$(TARGET) 4 4

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[1;3;32m%-30s\033[0m %s\n"