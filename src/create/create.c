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

    rpg->player = malloc(sizeof(player_t));
    rpg->player->clock = sfClock_create();
    rpg->player->texture = sfTexture_createFromFile(path_to_lama, NULL);
    if (!rpg->player->texture) {
        write(2, "Player spritesheet not found\n", 29);
        return (84);
    }
    rpg->player->sprite = sfSprite_create();
    sfSprite_setScale(rpg->player->sprite, (sfVector2f){2, 2});
    sfSprite_setTexture(rpg->player->sprite, rpg->player->texture, sfTrue);
    rpg->player->pos = rpg->levels[0]->player_start;
    sfSprite_setPosition(rpg->player->sprite, rpg->player->pos);
    rpg->player->rect = (sfIntRect){0, 0, 32, 32};
    rpg->player->speed = 5;
    sfSprite_setOrigin(rpg->player->sprite, (sfVector2f){16, 16});
    sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
    return(0);
}

void create(rpg_t *rpg)
{
    rpg->smenu = create_menu();
    rpg->smenu->win = rpg->window;
    create_player(rpg);
}

level_t **create_game_layout(const int nb_levels)
{
    level_t **levels = malloc(sizeof(level_t *) * (nb_levels + 3));
    char *path = NULL;
    int id = 0;
    char *id_str = NULL;

    levels[nb_levels + 2] = NULL;
    levels[0] = level_parser("assets/maps/txt/start");
    get_level_sprites_from_name(levels[0], "assets/maps/png/start");
    levels[nb_levels + 1] = level_parser("assets/maps/txt/end");
    get_level_sprites_from_name(levels[nb_levels + 1], "assets/maps/png/end");
    for (int i = 1; i < nb_levels + 1; i++) {
        id = (rand() % nb_levels) + 1;
        id_str = my_itos(id);
        path = my_strcat("assets/maps/txt/", id_str);
        levels[i] = level_parser(path);
        get_level_sprites_from_id(levels[i], id);
        free(id_str);
        free(path);
    }
    return (levels);
}