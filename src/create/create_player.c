/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_map.c
*/

#include "rpg.h"

int create_player(rpg_t *rpg)
{
    rpg->player.texture = sfTexture_createFromFile("assets/sprites/lama_sprite.png", NULL);
    if (!rpg->player.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    rpg->player.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->player.sprite, rpg->player.texture, sfTrue);
    rpg->player.pos.x = 0;
    rpg->player.pos.y = 500;
    sfSprite_setPosition(rpg->player.sprite, rpg->player.pos);
    rpg->player.rect.top = 0;
    rpg->player.rect.left = 0;
    rpg->player.rect.width = 64;
    rpg->player.rect.height = 64;
    sfSprite_setTextureRect(rpg->player.sprite, rpg->player.rect);
    return(0);
}