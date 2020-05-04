/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create.c
*/

#include "rpg.h"

player_t *create_player(rpg_t *rpg)
{
    player_t *player = malloc(sizeof(player_t));
    char *path_to_lama = "assets/sprites/lama_sprite_sheet.png";

    player = malloc(sizeof(player_t));
    player->clock = sfClock_create();
    player->texture = sfTexture_createFromFile(path_to_lama, NULL);
    if (!player->texture) {
        write(2, "Player spritesheet not found\n", 29);
        return (NULL);
    }
    player->direction = (sfVector2f){32, -20};
    player->sprite = sfSprite_create();
    sfSprite_setScale(player->sprite, (sfVector2f){2, 2});
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    player->pos = rpg->levels[0]->player_start;
    sfSprite_setPosition(player->sprite, player->pos);
    player->rect = (sfIntRect){0, 0, 32, 32};
    player->speed = 5;
    sfSprite_setOrigin(player->sprite, (sfVector2f){16, 16});
    sfSprite_setTextureRect(player->sprite, player->rect);
    return (player);
}

int create(rpg_t *rpg)
{
    rpg->smenu = create_menu();
    rpg->smenu->win = rpg->window;
    rpg->att.left_clicked = false;
    init_particle_environment(&rpg->att.particle_environment, \
    (sfVector2f){GRAVITY_X, GRAVITY_Y}, ALPHA);
    for (int i = 0; i < PARTICLE_MAX; i++)
        rpg->att.particle[i].living = false;
    init_particle_environment(&rpg->att.death_environment,\
    (sfVector2f){GRAVITY_X, GRAVITY_Y}, ALPHA);
    for (int i = 0; i < PARTICLE_MAX; i++)
        rpg->att.death[i].living = false;
    rpg->att.clock = sfClock_create();
    rpg->player = create_player(rpg);
    if (!rpg->player)
        return (sfFalse);
    rpg->player->damage = 2;
    rpg->player->hp = 500;
    create_sprite_inventory(rpg);
    create_sprite_merchant(rpg);
    create_softest(rpg);
    return (sfTrue);
}

int get_constant_levels(level_t **levels, const int nb_levels)
{
    levels[0] = level_parser("assets/maps/txt/start");
    levels[nb_levels - 1] = level_parser("assets/maps/txt/end");
    get_level_sprites_from_name(levels[0], "start");
    get_level_sprites_from_name(levels[nb_levels - 1], "end");
    if (!levels[0] || !levels[nb_levels - 1])
        return (sfFalse);
    return (sfTrue);
}

int get_level_id(const int nb_levels, bool reset)
{
    int id = (rand() % (nb_levels - 2)) + 1;
    static bool taken[NB_LEVELS - 2] = {};

    if (reset) {
        for (int i = 0; i < NB_LEVELS - 2; i++)
            taken[i] = false;
        return (-1);
    }
    while (taken[id])
        id = (rand() % (nb_levels - 2)) + 1;
    taken[id] = true;
    return (id);
}

level_t **create_game_layout(const int nb_levels)
{
    level_t **levels = malloc(sizeof(level_t *) * (7 + 1));
    char *path = NULL;
    char *id_str = NULL;

    levels[7] = NULL;
    if (!get_constant_levels(levels, 7))
        return (NULL);
    for (int i = 1; i < 6; i++) {
        id_str = my_itos(get_level_id(nb_levels, false));
        path = my_strcat("assets/maps/txt/", id_str);
        levels[i] = level_parser(path);
        if (levels[i])
            get_level_sprites_from_name(levels[i], id_str);
        if (!levels[i] || !levels[i]->texture || !levels[i]->ol_texture)
            return (ptr_message("lvl/texture lding failed\n", NULL, 2, NULL));
        free(id_str);
        free(path);
    }
    get_level_id(nb_levels, true);
    return (levels);
}