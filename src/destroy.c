/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy.c
*/

#include "rpg.h"

void destroy_player(player_t *player)
{
    sfClock_destroy(player->clock);
    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
}

void destroy_image(button_t *button, parallax_t *parallax)
{
    if (!parallax) {
        sfSprite_destroy(button->sprite);
        sfTexture_destroy(button->texture);
    } else {
        sfSprite_destroy(parallax->sprite);
        sfTexture_destroy(parallax->texture);
    }
}

void destroy_menu(smenu_t *menu)
{
    destroy_image(&menu->play_on, NULL);
    destroy_image(&menu->play_off, NULL);
    destroy_image(&menu->save_on, NULL);
    destroy_image(&menu->save_off, NULL);
    destroy_image(&menu->quit_on, NULL);
    destroy_image(&menu->quit_off, NULL);
    destroy_image(&menu->htp_on, NULL);
    destroy_image(&menu->htp_off, NULL);
    destroy_image(&menu->setting_on, NULL);
    destroy_image(&menu->setting_off, NULL);
    destroy_image(&menu->setting_back, NULL);
    destroy_image(&menu->plus_on, NULL);
    destroy_image(&menu->plus_off, NULL);
    destroy_image(&menu->less_on, NULL);
    destroy_image(&menu->less_off, NULL);
    for (int i = 0; menu->para[i]; i++) {
        destroy_image(NULL, menu->para[i]);
        free(menu->para[i]);
    }
    free(menu->para);
}

void destroy_levels(level_t **levels)
{
    for (int i = 0; levels[i]; i++) {
        for (int en = 0; levels[i]->enemies[en]; en++) {
            //sfSprite_destroy(levels[i]->enemies[en]->sprite);
            //sfTexture_destroy(levels[i]->enemies[en]->texture);
            free(levels[i]->enemies[en]);
        }
        free(levels[i]->enemies);
        for (int col = 0; levels[i]->collisions[col]; col++)
            free(levels[i]->collisions[col]);
        free(levels[i]->collisions);
        sfSprite_destroy(levels[i]->sprite);
        sfSprite_destroy(levels[i]->ol_sprite);
        sfTexture_destroy(levels[i]->texture);
        sfTexture_destroy(levels[i]->ol_texture);
    }
    free(levels);
}

void destroy_rpg(rpg_t *rpg)
{
    write(2, "Destroying player struct...\n", 28);
    destroy_player(rpg->player);
    write(2, "Done!\nDestroying menu struct...\n", 32);
    destroy_menu(rpg->smenu);
    write(2, "Done!\nDestroying levels struct...\n", 34);
    destroy_levels(rpg->levels);
    write(2, "Done!\nDestroying window...\n", 27);
    sfRenderWindow_destroy(rpg->window);
    write(2, "All done!\nBye!\n", 10);
}
