/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** initialise_struct_rpg.c
*/

#include "rpg.h"

void initialise_value_struct_rpg(rpg_t *rpg)
{
    rpg->clock_display.clock = sfClock_create();
    rpg->clock_player.clock = sfClock_create();
    rpg->clock_move_rect_player.clock = sfClock_create();
    rpg->bool_menu = 0;
    rpg->event = malloc(sizeof(rpg->event));
}

int initialise_struct_window(rpg_t *rpg)
{
    rpg->window.mode.width = WIDTH;
    rpg->window.mode.height = HEIGHT;
    rpg->window.mode.bitsPerPixel = 32;
    rpg->window.window = sfRenderWindow_create(rpg->window.mode,
    "MY_RPG", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(rpg->window.window, 60);
    if (!rpg->window.window) {
        write(2, "error, window not display\n", 27);
        return (84);
    }
    return (0);
}

int initialise_value_struct(rpg_t *rpg)
{
    initialise_value_struct_rpg(rpg);
    if (initialise_struct_window(rpg))
        return (84);
    return (0);
}