##
## EPITECH PROJECT, 2019
## MUL_my_rpg_2019
## File description:
## Makefile
##

RM			=	rm -f
CC			=	gcc
CFLAGS		=	-W -Wall -Wextra -Iinclude/
LDFLAGS		=	-L./ -lmy -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lm
SRC			=	src/main.c										\
				src/main_loop.c									\
				src/end_loop.c									\
				src/init/init_rpg.c								\
				src/init/create.c								\
				src/cutscenes/play_cutscene.c					\
				src/cutscenes/cutscene_events.c					\
				src/cutscenes/cutscene_texts.c					\
				src/parsing/collision_parser.c					\
				src/parsing/level_parser.c						\
				src/parsing/level_parser_two.c					\
				src/parsing/error_handling.c					\
				src/level_loading/get_level_sprites.c			\
				src/level_loading/change_levels.c				\
				src/enemies/enemy_loading.c						\
				src/enemies/draw_enemies.c						\
				src/enemies/update_enemies.c					\
				src/enemies/enemy_movement.c					\
				src/enemies/enemy_collisions.c					\
				src/enemies/boss_mv.c							\
				src/display/display.c							\
				src/display/draw_text_box.c						\
				src/move/intersections.c						\
				src/move/move_player.c							\
				src/move/set_movement.c							\
				src/move/vector_calculus.c						\
				src/clock/clock.c								\
				src/events/game_events.c						\
				src/events/update_game.c						\
				src/attack/particle.c							\
				src/attack/death.c								\
				src/start_menu/start_menu.c						\
				src/start_menu/create_start_menu.c				\
				src/start_menu/setting_loop.c					\
				src/start_menu/htp_loop.c						\
				src/start_menu/move_rect.c						\
				src/start_menu/button/play_button.c				\
				src/start_menu/button/how_to_play_button.c		\
				src/start_menu/button/quit_button.c				\
				src/start_menu/button/setting_button.c			\
				src/start_menu/button/return_button.c			\
				src/start_menu/button/plus_button.c				\
				src/start_menu/button/less_button.c				\
				src/sound/music.c								\
				src/destroy.c									\
				src/inventory/create_inventory.c				\
				src/inventory/draw_inventory.c					\
				src/merchant/merchant.c							\
				src/merchant/create_potion_red.c				\
				src/merchant/create_potion_yellow.c				\
				src/merchant/draw_merchant.c					\
				src/merchant/draw_information.c					\
				src/merchant/boots_1.c							\
				src/merchant/boots_2.c							\
				src/merchant/boots_3.c							\
				src/merchant/shield_1.c							\
				src/merchant/shield_2.c							\
				src/merchant/shield_3.c							\
				src/merchant/create_potion_blue.c				\
				src/pause/pause_menu.c							\
				src/pause/resume_button.c						\
				src/display/print_xp.c							\
				src/display/print_hp.c							\
				src/display/print_informations.c				\
				src/npc/npc.c									\
				src/npc/bubble.c								\
				src/npc/create_npc.c							\
				src/pause/pause_option_button.c
OBJ			=	$(SRC:.c=.o)
NAME		=	my_rpg

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my/ > /dev/null
	$(CC) -o $@ $^ $(LDFLAGS)

.SILENT: clean

clean:
	$(RM) $(OBJ)
	$(RM) libmy.a

fclean: clean
	$(RM) $(NAME)
	$(RM) log

re: fclean all