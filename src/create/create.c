/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create.c
*/

#include "rpg.h"

int create_player(rpg_t *rpg)
{
    char *path_to_lama = "assets/sprites/lama_sprite_sheet.png";

    rpg->player.texture = sfTexture_createFromFile(path_to_lama, NULL);
    if (!rpg->player.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    rpg->player.sprite = sfSprite_create();
    sfSprite_setScale(rpg->player.sprite, (sfVector2f){2, 2});
    sfSprite_setTexture(rpg->player.sprite, rpg->player.texture, sfTrue);
    rpg->player.pos.x = 10;
    rpg->player.pos.y = 550;
    sfSprite_setPosition(rpg->player.sprite, rpg->player.pos);
    rpg->player.rect.top = 0;
    rpg->player.rect.left = 0;
    rpg->player.rect.width = 32;
    rpg->player.rect.height = 32;
    sfSprite_setOrigin(rpg->player.sprite, (sfVector2f){16, 16});
    sfSprite_setTextureRect(rpg->player.sprite, rpg->player.rect);
    return(0);
}

void create(rpg_t *rpg)
{
    rpg->smenu = create_menu();
    rpg->smenu->win = rpg->window.window;
    create_map1(rpg);
    // create_map2(rpg);
    // create_map3(rpg);
    create_player(rpg);
}