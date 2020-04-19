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
SRC			=	src/main.c										\
				src/cutscenes/play_cutscene.c					\
				src/main_loop.c									\
				src/parsing/collision_parser.c					\
				src/parsing/level_parser.c						\
				src/parsing/error_handling.c					\
				src/level_loading/get_level_sprites.c			\
				src/level_loading/change_levels.c				\
				src/level_loading/enemy_loading.c				\
				src/initialize/initialize_struct_rpg.c			\
				src/create/create.c								\
				src/display/display.c							\
				src/move/move_player.c							\
				src/move/set_movement.c							\
				src/clock/clock.c								\
				src/events/open_close.c							\
				src/start_menu/start_menu.c						\
				src/start_menu/setting_loop.c					\
				src/start_menu/parallax/move_parallax.c			\
				src/start_menu/parallax/create_parallax.c		\
				src/start_menu/button/play_button.c				\
				src/start_menu/button/save_button.c				\
				src/start_menu/button/how_to_play_button.c		\
				src/start_menu/button/quit_button.c				\
				src/start_menu/button/setting_button.c			\
				src/start_menu/button/return_button.c			\
				src/start_menu/button/plus_button.c				\
				src/start_menu/button/less_button.c				\
				src/sound/music.c								\
				src/destroy.c
TEST_SRC	=	tests/*.c
OBJ			=	$(SRC:.c=.o)
TEST_OBJ	=	$(TEST_SRC:.c=.o)
NAME		=	my_rpg
TEST_NAME	=	./unit-tests

all: $(NAME)

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
