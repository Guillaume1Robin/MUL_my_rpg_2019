/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** bouclier_1.c
*/

#include "rpg.h"

int create_sprite_shield_1(rpg_t *rpg)
{
    char *path_to_button = "assets/sprites/shield1.png";

    rpg->shield_1.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!rpg->shield_1.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    rpg->shield_1.boulean = 0;
    rpg->shield_1.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->shield_1.sprite, rpg->shield_1.texture, sfTrue);
    rpg->shield_1.rect.top = 0;
    rpg->shield_1.rect.left = 0;
    rpg->shield_1.rect.width = 23;
    rpg->shield_1.rect.height = 31;
    sfVector2f shield_1_size = {2.0, 2.0};
    sfSprite_setScale(rpg->shield_1.sprite, shield_1_size);
    return (0);
}

void update_shield_1(rpg_t *rpg)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(rpg->window);
    sfFloatRect shield_1_rect = sfSprite_getGlobalBounds(rpg->shield_1.sprite);

    if (sfFloatRect_contains(&shield_1_rect, (float)mp.x, (float)mp.y)) {
        rpg->check_item = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft) && rpg->xp >= 5 && \
        rpg->shield_1.boulean == 0) {
            rpg->shield = 1;
            rpg->xp -= 5;
            rpg->shield_1.boulean = 1;
            rpg->shield_2.boulean = 0;
            rpg->shield_3.boulean = 0;
            rpg->player->hp += 100;
        }
    }
}