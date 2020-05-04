/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** enemy_loading.c
*/

#include "rpg.h"

sfBool get_bat_percs(enemy_t *enemy)
{
    enemy->max = 128;
    enemy->hp = 2000;
    enemy->start_hp = 2000;
    enemy->fps = 0.07;
    enemy->damage = 1;
    enemy->alive = sfTrue;
    enemy->speed = 10;
    enemy->knockback = -0.75;
    enemy->sprite = sfSprite_create();
    enemy->texture = sfTexture_createFromFile("assets/sprites/Bat.png", NULL);
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    enemy->rect = (sfIntRect){0, 0, 32, 32};
    sfSprite_setPosition(enemy->sprite, enemy->start_pos);
    sfSprite_setScale(enemy->sprite, (sfVector2f){1.5, 1.5});
    sfSprite_setOrigin(enemy->sprite, (sfVector2f){16, 16});
    if (!enemy->texture)
        return (sfFalse);
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    return (sfTrue);
}

sfBool get_slug_percs(enemy_t *enemy)
{
    enemy->max = 320;
    enemy->fps = 0.16;
    enemy->hp = 6000;
    enemy->start_hp = 6000;
    enemy->damage = 2;
    enemy->alive = sfTrue;
    enemy->speed = 8;
    enemy->knockback = -0.10;
    enemy->sprite = sfSprite_create();
    enemy->texture = sfTexture_createFromFile("assets/sprites/Slug.png", NULL);
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    enemy->rect = (sfIntRect){0, 0, 64, 32};
    sfSprite_setPosition(enemy->sprite, enemy->start_pos);
    sfSprite_setScale(enemy->sprite, (sfVector2f){1.5, 1.5});
    sfSprite_setOrigin(enemy->sprite, (sfVector2f){32, 16});
    if (!enemy->texture)
        return (sfFalse);
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    return (sfTrue);
}

sfBool get_egg_percs(enemy_t *enemy)
{
    enemy->max = 192;
    enemy->fps = 0.1;
    enemy->hp = 4500;
    enemy->start_hp = 4500;
    enemy->damage = 3;
    enemy->alive = sfTrue;
    enemy->speed = 11;
    enemy->knockback = -0.20;
    enemy->sprite = sfSprite_create();
    enemy->texture = sfTexture_createFromFile("assets/sprites/Egg.png", NULL);
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    enemy->rect = (sfIntRect){0, 0, 32, 48};
    sfSprite_setPosition(enemy->sprite, enemy->start_pos);
    sfSprite_setScale(enemy->sprite, (sfVector2f){1.5, 1.5});
    sfSprite_setOrigin(enemy->sprite, (sfVector2f){16, 24});
    if (!enemy->texture)
        return (sfFalse);
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    return (sfTrue);
}

sfBool get_miniboss_percs(enemy_t *enemy)
{
    enemy->max = 405;
    enemy->hp = 20000;
    enemy->start_hp = 20000;
    enemy->fps = 0.1;
    enemy->damage = 5;
    enemy->alive = sfTrue;
    enemy->speed = 12;
    enemy->knockback = 0;
    enemy->sprite = sfSprite_create();
    enemy->texture = sfTexture_createFromFile("assets/sprites/Mini.png", NULL);
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    enemy->rect = (sfIntRect){0, 0, 45, 50};
    sfSprite_setPosition(enemy->sprite, enemy->start_pos);
    sfSprite_setScale(enemy->sprite, (sfVector2f){2.5, 2.5});
    sfSprite_setOrigin(enemy->sprite, (sfVector2f){23, 25});
    if (!enemy->texture)
        return (sfFalse);
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    return (sfTrue);
}

sfBool get_boss_percs(enemy_t *enemy)
{
    enemy->max = 64;
    enemy->hp = 45000;
    enemy->start_hp = 45000;
    enemy->damage = 5;
    enemy->alive = sfTrue;
    enemy->speed = 25;
    enemy->knockback = -0.01;
    enemy->sprite = sfSprite_create();
    enemy->texture = sfTexture_createFromFile("assets/sprites/Boss.png", NULL);
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    enemy->rect = (sfIntRect){0, 0, 64, 64};
    sfSprite_setPosition(enemy->sprite, enemy->start_pos);
    sfSprite_setScale(enemy->sprite, (sfVector2f){3, 3});
    sfSprite_setOrigin(enemy->sprite, (sfVector2f){32, 32});
    if (!enemy->texture)
        return (sfFalse);
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    return (sfTrue);
}