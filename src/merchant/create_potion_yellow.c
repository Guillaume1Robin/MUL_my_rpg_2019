/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_potion_yellow.c
*/

#include "rpg.h"

int create_sprite_potion_yellow(rpg_t *rpg)
{
    char *path_to_button = "assets/sprites/fiole_yellow.png";

    rpg->potion_yellow.texture = sfTexture_createFromFile(path_to_button, NULL\
);
    if (!rpg->potion_yellow.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    rpg->potion_yellow.boulean = 0;
    rpg->potion_yellow.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->potion_yellow.sprite, \
    rpg->potion_yellow.texture, sfTrue);
    rpg->potion_yellow.rect.top = 0;
    rpg->potion_yellow.rect.left = 0;
    rpg->potion_yellow.rect.width = 23;
    rpg->potion_yellow.rect.height = 31;
    sfVector2f potion_yellow_size = {2.0, 2.0};
    sfSprite_setScale(rpg->potion_yellow.sprite, potion_yellow_size);
    return (0);
}

void update_potion_yellow(rpg_t *rpg)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(rpg->window);
    sfFloatRect yellow = sfSprite_getGlobalBounds(rpg->potion_yellow.sprite);

    if (sfFloatRect_contains(&yellow, (float)mp.x, (float)mp.y)) {
        rpg->check_item = 3;
        if (sfMouse_isButtonPressed(sfMouseLeft) && rpg->xp >= 15 && \
        rpg->potion_yellow.boulean == 0) {
            rpg->potion = 3;
            rpg->xp -= 15;
            rpg->potion_yellow.boulean = 1;
            rpg->potion_red.boulean = 0;
            rpg->potion_blue.boulean = 0;
        }
    }
}