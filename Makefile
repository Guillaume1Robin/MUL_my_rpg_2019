##
## EPITECH PROJECT, 2019
## MUL_my_rpg_2019
## File description:
## Makefile
##

RM			=	rm -rf
CC			=	gcc
CFLAGS		=	-W -Wall -Wextra -Iinclude/ -g3
LDFLAGS		=	-L./ -lmy -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system
TEST_LDFLAGS=	-lcriterion --coverage -L./ -lmy
SRC			=	src/parser.c								\
				src/main.c									\
				src/window/open_window.c					\
				src/initialise_value/initialise_struct_rpg.c\
				src/create/create.c							\
				src/create/create_window.c					\
				src/create/create_map.c						\
				src/create/create_player.c					\
				src/display/display.c						\
				src/move/move_player.c						\
				src/clock/clock.c							\
				src/events/open_close.c						\
				src/start_menu/start_menu.c					\
				src/start_menu/parallax/parallax_menu.c		\
				src/start_menu/parallax/move_parallax.c		\
				src/start_menu/parallax/create_parallax.c	\
				src/start_menu/button/button_play.c			\
				src/start_menu/button/button_save.c			\
				src/start_menu/button/button_how_to_play.c	\
				src/start_menu/button/button_quit.c
TEST_SRC	=	tests/*.c
OBJ			=	$(SRC:.c=.o)
TEST_OBJ	=	$(TEST_SRC:.c=.o)
NAME		=	my_rpg
TEST_NAME	=	./unit-tests

all: $(NAME) clean

$(NAME): $(OBJ)
	make -C ./lib/my/ > /dev/null
	$(CC) -o $@ $^ $(LDFLAGS)

$(TEST_NAME): $(TEST_OBJ)
	make -C ./lib/my/
	$(CC) -o $@ $^ $(TEST_LDFLAGS)

.SILENT: clean

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
