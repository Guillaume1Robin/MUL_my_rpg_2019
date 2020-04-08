/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_map.c
*/

#include "rpg.h"

int create_map1(rpg_t *rpg)
{
    char *name = "assets/sprites/map5.png";

    rpg->map.texture = sfTexture_createFromFile(name, NULL);
    if (!rpg->map.texture) {
        write(2, "error missing the button\n", 25);
        return (84);
    }
    rpg->map.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->map.sprite, rpg->map.texture, sfTrue);
    sfSprite_setPosition(rpg->map.sprite, rpg->map.pos);
    return (0);
}

// int create_map2(rpg_t *rpg)
// {
//     char *name = "assets/sprites/map2.png";

//     rpg->map.texture = sfTexture_createFromFile(name, NULL);
//     if (!rpg->map.texture) {
//         write(2, "error missing the button\n", 25);
//         return (84);
//     }
//     rpg->map.sprite = sfSprite_create();
//     sfSprite_setTexture(rpg->map.sprite, rpg->map.texture, sfTrue);
//     sfSprite_setPosition(rpg->map.sprite, rpg->map.pos);
//     return (0);
// }

// int create_map3(rpg_t *rpg)
// {
//     char *name = "assets/sprites/map3.png";

//     rpg->map.texture = sfTexture_createFromFile(name, NULL);
//     if (!rpg->map.texture) {
//         write(2, "error missing the button\n", 25);
//         return (84);
//     }
//     rpg->map.sprite = sfSprite_create();
//     sfSprite_setTexture(rpg->map.sprite, rpg->map.texture, sfTrue);
//     sfSprite_setPosition(rpg->map.sprite, rpg->map.pos);
//     return (0);
// }