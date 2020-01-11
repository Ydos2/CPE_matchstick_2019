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

OBJ     =	$(SRC:.c=.o) 			\

COVERAGE		=	$(SRC:.c=.gcda)				\
					$(MAIN_SRC:.c=.gcda)		\
					$(TEST_SRC:.c=.gcda)		\
					$(SRC:.c=.gcno)				\
					$(MAIN_SRC:.c=.gcno)		\
					$(TEST_SRC:.c=.gcno)		\

MAIN_SRC    =    src/main.c			\

MAIN_OBJ    =    $(MAIN_SRC:.c=.o)	\

CFLAGS    =    -I./include -Wextra --coverage -g3

TARGET    =		matchstick		\

TEST_SRC     =     tests/criterion.c		\

TEST_OBJ     =     $(TEST_SRC:.c=.o)

TEST_TARGET     =     unit_tests

LDFLAGS     =     -lcriterion -lgcov --coverage

all: $(TARGET)

build_lib:
	cd lib/my/ && make
	cp lib/my/libmy.a lib/
	cp lib/my/my.h include/

$(TARGET): $(OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MAIN_OBJ) -o $(TARGET)

%.o : %.c
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(MAIN_OBJ) $(TEST_OBJ) $(COVERAGE)

fclean: clean
	rm -f $(TARGET) $(TEST_TARGET)

re:    fclean all

tests_build: $(OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(TEST_OBJ) -o $(TEST_TARGET)

tests_run:
	$(CC) -o unit_tests $(LDFLAGS) $(SRC) $(TEST_SRC) $(CFLAGS)
	./$(TEST_TARGET)
	gcovr --exclude tests/

re_tests: fclean tests_run