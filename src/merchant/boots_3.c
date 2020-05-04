/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** boots_3.c
*/

#include "rpg.h"

int create_sprite_boots_3(rpg_t *rpg)
{
    char *path_to_button = "assets/sprites/boots3.png";

    rpg->boots_3.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!rpg->boots_3.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    rpg->boots_3.boulean = 0;
    rpg->boots_3.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->boots_3.sprite, rpg->boots_3.texture, sfTrue);
    rpg->boots_3.rect.top = 0;
    rpg->boots_3.rect.left = 0;
    rpg->boots_3.rect.width = 23;
    rpg->boots_3.rect.height = 31;
    sfVector2f boots_3_size = {2.0, 2.0};
    sfSprite_setScale(rpg->boots_3.sprite, boots_3_size);
    return (0);
}

void update_boots_3(rpg_t *rpg)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(rpg->window);
    sfFloatRect boots_3_rect = sfSprite_getGlobalBounds(rpg->boots_3.sprite);

    if (sfFloatRect_contains(&boots_3_rect, (float)mp.x, (float)mp.y)) {
        rpg->check_item = 3;
        if (sfMouse_isButtonPressed(sfMouseLeft) && rpg->xp >= 15 && \
        rpg->boots_3.boulean == 0) {
            rpg->xp -= 15;
            rpg->boots = 3;
            rpg->boots_3.boulean = 1;
            rpg->boots_1.boulean = 0;
            rpg->boots_2.boulean = 0;
        }
    }
}