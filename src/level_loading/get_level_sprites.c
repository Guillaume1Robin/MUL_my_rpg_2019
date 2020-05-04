/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** get_level_sprites.c
*/

#include "rpg.h"

void get_level_sprites_from_name(level_t *level, const char *name)
{
    char *path = "assets/maps/png/";
    char *tmp1 = my_strcat(name, ".png");
    char *tmp2 = my_strcat(name, "overlay.png");
    char *texture_path = my_strcat(path, tmp1);
    char *ol_texture_path = my_strcat(path, tmp2);

    free(tmp1);
    free(tmp2);
    level->texture = NULL;
    level->ol_texture = NULL;
    level->sprite = sfSprite_create();
    level->ol_sprite = sfSprite_create();
    level->texture = sfTexture_createFromFile(texture_path, NULL);
    level->ol_texture = sfTexture_createFromFile(ol_texture_path, NULL);
    sfSprite_setTexture(level->sprite, level->texture, sfTrue);
    sfSprite_setTexture(level->ol_sprite, level->ol_texture, sfTrue);
    sfSprite_setPosition(level->sprite, (sfVector2f){0, 0});
    sfSprite_setPosition(level->ol_sprite, (sfVector2f){0, 0});
    free(texture_path);
    free(ol_texture_path);
}

void get_level_sprites_from_id(level_t *level, int id)
{
    char *id_str = my_itos(id);
    char *text_file = my_strcat(id_str, "map.png");
    char *ol_file = my_strcat(id_str, "overlaymap.png");
    char *texture_path = my_strcat("assets/maps/png/", text_file);
    char *ol_texture_path = my_strcat("assets/maps/png/", ol_file);

    level->sprite = sfSprite_create();
    level->ol_sprite = sfSprite_create();
    level->texture = sfTexture_createFromFile(texture_path, NULL);
    level->ol_texture = sfTexture_createFromFile(ol_texture_path, NULL);
    sfSprite_setTexture(level->sprite, level->texture, sfTrue);
    sfSprite_setTexture(level->ol_sprite, level->ol_texture, sfTrue);
    sfSprite_setPosition(level->sprite, (sfVector2f){0, 0});
    sfSprite_setPosition(level->ol_sprite, (sfVector2f){0, 0});
    free(id_str);
    free(text_file);
    free(ol_file);
    free(texture_path);
    free(ol_texture_path);
}