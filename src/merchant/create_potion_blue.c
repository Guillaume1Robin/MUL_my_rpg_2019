/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_potion_blue.c
*/

#include "rpg.h"

int create_sprite_potion_blue(rpg_t *rpg)
{
    char *path_to_button = "assets/sprites/fiole_blue.png";

    rpg->potion_blue.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!rpg->potion_blue.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    rpg->potion_blue.boulean = 0;
    rpg->potion_blue.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->potion_blue.sprite, \
    rpg->potion_blue.texture, sfTrue);
    rpg->potion_blue.rect.top = 0;
    rpg->potion_blue.rect.left = 0;
    rpg->potion_blue.rect.width = 23;
    rpg->potion_blue.rect.height = 31;
    sfVector2f potion_blue_size = {2.0, 2.0};
    sfSprite_setScale(rpg->potion_blue.sprite, potion_blue_size);
    return (0);
}

void update_potion_blue(rpg_t *rpg)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(rpg->window);
    sfFloatRect blue_rect = sfSprite_getGlobalBounds(rpg->potion_blue.sprite);

    if (sfFloatRect_contains(&blue_rect, (float)mp.x, (float)mp.y)) {
        rpg->check_item = 2;
        if (sfMouse_isButtonPressed(sfMouseLeft) && rpg->xp >= 10 && \
        rpg->potion_blue.boulean == 0) {
            rpg->potion = 2;
            rpg->xp -= 10;
            rpg->potion_blue.boulean = 1;
            rpg->potion_yellow.boulean = 0;
            rpg->potion_red.boulean = 0;
        }
    }
}