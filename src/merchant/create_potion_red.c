/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_potion.c
*/

#include "rpg.h"

int create_sprite_potion_red(rpg_t *rpg)
{
    char *path_to_button = "assets/sprites/fiole_red.png";

    rpg->potion_red.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!rpg->potion_red.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    rpg->potion_red.boulean = 0;
    rpg->potion_red.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->potion_red.sprite, \
    rpg->potion_red.texture, sfTrue);
    rpg->potion_red.rect.top = 0;
    rpg->potion_red.rect.left = 0;
    rpg->potion_red.rect.width = 23;
    rpg->potion_red.rect.height = 31;
    sfVector2f potion_red_size = {2.0, 2.0};
    sfSprite_setScale(rpg->potion_red.sprite, potion_red_size);
    return (0);
}

void update_potion_red(rpg_t *rpg)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(rpg->window);
    sfFloatRect red_rect = sfSprite_getGlobalBounds(rpg->potion_red.sprite);

    if (sfFloatRect_contains(&red_rect, (float)mp.x, (float)mp.y)) {
        rpg->check_item = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft) && rpg->xp >= 5 && \
        rpg->potion_red.boulean == 0) {
            rpg->potion = 1;
            rpg->xp -= 5;
            rpg->potion_red.boulean = 1;
            rpg->potion_blue.boulean = 0;
            rpg->potion_yellow.boulean = 0;
        }
    } else
        rpg->check_item = 0;
}