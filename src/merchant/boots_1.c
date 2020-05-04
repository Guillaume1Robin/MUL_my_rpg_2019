/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** boots_2.c
*/

#include "rpg.h"

int create_sprite_boots_1(rpg_t *rpg)
{
    char *path_to_button = "assets/sprites/boots1.png";

    rpg->boots_1.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!rpg->boots_1.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    rpg->boots_1.boulean = 0;
    rpg->boots_1.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->boots_1.sprite, rpg->boots_1.texture, sfTrue);
    rpg->boots_1.rect.top = 0;
    rpg->boots_1.rect.left = 0;
    rpg->boots_1.rect.width = 23;
    rpg->boots_1.rect.height = 31;
    sfVector2f boots_1_size = {2.0, 2.0};
    sfSprite_setScale(rpg->boots_1.sprite, boots_1_size);
    return (0);
}

void update_boots_1(rpg_t *rpg)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(rpg->window);
    sfFloatRect boots_1_rect = sfSprite_getGlobalBounds(rpg->boots_1.sprite);

    if (sfFloatRect_contains(&boots_1_rect, (float)mp.x, (float)mp.y)) {
        rpg->check_item = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft) && rpg->xp >= 5 && \
        rpg->boots_1.boulean == 0) {
            rpg->boots = 1;
            rpg->xp -= 5;
            rpg->boots_1.boulean = 1;
            rpg->boots_2.boulean = 0;
            rpg->boots_3.boulean = 0;
        }
    }
}