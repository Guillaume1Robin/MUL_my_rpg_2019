/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_map.c
*/

#include "rpg.h"

int create_map(rpg_t *rpg)
{
    rpg->map.texture = sfTexture_createFromFile("assets/sprites/map1.png", NULL);
    // if (!rpg->map.texture) {
    //     write(2, "error missing the button\n", 26);
    //     return (84);
    // }
    rpg->map.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->map.sprite, rpg->map.texture, sfTrue);
    sfSprite_setPosition(rpg->map.sprite, rpg->map.pos);

    return (0);
}