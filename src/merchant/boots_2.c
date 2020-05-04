/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** boots_1.c
*/

#include "rpg.h"

int create_sprite_boots_2(rpg_t *rpg)
{
    char *path_to_button = "assets/sprites/boots2.png";

    rpg->boots_2.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!rpg->boots_2.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    rpg->boots_2.boulean = 0;
    rpg->boots_2.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->boots_2.sprite, rpg->boots_2.texture, sfTrue);
    rpg->boots_2.rect.top = 0;
    rpg->boots_2.rect.left = 0;
    rpg->boots_2.rect.width = 23;
    rpg->boots_2.rect.height = 31;
    sfVector2f boots_2_size = {2.0, 2.0};
    sfSprite_setScale(rpg->boots_2.sprite, boots_2_size);
    return (0);
}

void update_boots_2(rpg_t *rpg)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(rpg->window);
    sfFloatRect boots_2_rect = sfSprite_getGlobalBounds(rpg->boots_2.sprite);

    if (sfFloatRect_contains(&boots_2_rect, (float)mp.x, (float)mp.y)) {
        rpg->check_item = 2;
        if (sfMouse_isButtonPressed(sfMouseLeft) && rpg->xp >= 10 && \
        rpg->boots_2.boulean == 0) {
            rpg->boots = 2;
            rpg->xp -= 10;
            rpg->boots_2.boulean = 1;
            rpg->boots_1.boulean = 0;
            rpg->boots_3.boulean = 0;
        }
    }
}