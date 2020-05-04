/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main.c
*/

#include "rpg.h"

int main(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    sfImage *icon = sfImage_createFromFile("assets/sprites/title.png");
    sfVector2u size = sfImage_getSize(icon);
    const sfUint8 *pxptr = sfImage_getPixelsPtr(icon);

    if (init_rpg(rpg)) {
        if (icon)
            sfRenderWindow_setIcon(rpg->window, size.x, size.y, pxptr);
        play_music(rpg);
        main_loop(rpg);
        destroy_rpg(rpg);
        sfImage_destroy(icon);
        free(rpg);
        return (0);
    }
    return (84);
}