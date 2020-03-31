##
## EPITECH PROJECT, 2019
## navy
## File description:
## Makefile
##

RM			=	rm -rf
CC			=	gcc
CFLAGS		=	-W -Wall -Wextra -Iinclude/ -g3
LDFLAGS		=	-L./ -lmy -lncurses
TEST_LDFLAGS=	-lcriterion --coverage -L./ -lmy
SRC			=	src/parser.c
TEST_SRC	=	tests/*.c
OBJ			=	$(SRC:.c=.o)
TEST_OBJ	=	$(TEST_SRC:.c=.o)
NAME		=	rpg
TEST_NAME	=	./unit-tests

all: $(NAME)
	make clean

$(NAME): $(OBJ)
	make -C ./lib/my/ > /dev/null
	$(CC) -o $@ $^ $(LDFLAGS)

$(TEST_NAME): $(TEST_OBJ)
	make -C ./lib/my/
	$(CC) -o $@ $^ $(TEST_LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) libmy.a
	$(RM) $(TEST_OBJ)
	$(RM) $(TEST_NAME)
	$(RM) $(OBJ:.o=.gcno)
	$(RM) $(OBJ:.o=.gcda)

fclean: clean
	$(RM) $(NAME)
	$(RM) log

re: fclean all

tests_run: $(TEST_NAME)
	$(TEST_NAME); gcovr