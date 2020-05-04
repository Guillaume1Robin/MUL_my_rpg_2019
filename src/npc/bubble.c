/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** bubble.c
*/

#include "rpg.h"

int create_sprite_bubble(rpg_t *rpg)
{
    char *name = "assets/sprites/bubble.png";

    rpg->bubble.texture = sfTexture_createFromFile(name, NULL);
    if (!rpg->bubble.texture) {
        write(1, "error missing the button\n", 26);
        return (84);
    }
    rpg->bubble.sprite = sfSprite_create();
    rpg->bubble.clock = sfClock_create();
    sfSprite_setTexture(rpg->bubble.sprite, rpg->bubble.texture, sfTrue);
    rpg->bubble.pos.x = 1020;
    rpg->bubble.pos.y = 190;
    sfSprite_setPosition(rpg->bubble.sprite, rpg->bubble.pos);
    rpg->bubble.rect.top = 0;
    rpg->bubble.rect.left = 0;
    rpg->bubble.rect.width = 52;
    rpg->bubble.rect.height = 48;
    sfSprite_setTextureRect(rpg->bubble.sprite, rpg->bubble.rect);
    return (0);
}

void move_bubble(rpg_t *rpg)
{
    move_rect(&rpg->bubble.rect, 52, 104);
    sfClock_restart(rpg->bubble.clock);
    sfSprite_setTextureRect(rpg->bubble.sprite, rpg->bubble.rect);
}

void move_rect(sfIntRect *rectangle, int offset, int max_value)
{
    rectangle->left = rectangle->left + offset;
    if (rectangle->left > max_value)
        rectangle->left = 0;
}