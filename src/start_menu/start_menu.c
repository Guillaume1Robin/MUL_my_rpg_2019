/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu_principal.c
*/

#include "rpg.h"

smenu_t *create_menu(void)
{
    smenu_t *smenu = malloc(sizeof(smenu_t));

    create_parallax(smenu);
    create_sprite_button_play_on(smenu);
    create_sprite_play_off(smenu);
    create_sprite_button_save_on(smenu);
    create_sprite_save_off(smenu);
    create_sprite_button_htp_on(smenu);
    create_sprite_htp_off(smenu);
    create_sprite_button_quit_on(smenu);
    create_sprite_quit_off(smenu);
    smenu->play_off.boulen_button = 0;
    smenu->save_off.boulen_button = 0;
    smenu->htp_off.boulen_button = 0;
    smenu->quit_off.boulen_button = 0;
     smenu->play_on.boulen_button = 0;
    smenu->save_on.boulen_button = 0;
    smenu->htp_on.boulen_button = 0;
    smenu->quit_on.boulen_button = 0;
    smenu->bool = sfTrue;
    return (smenu);
}

void display_button(smenu_t *smenu)
{
    if (smenu->play_off.boulen_button == 0)
        sfRenderWindow_drawSprite(smenu->win, smenu->play_on.sprite, NULL);
    else
        sfRenderWindow_drawSprite(smenu->win, smenu->play_off.sprite, NULL);
    if (smenu->save_off.boulen_button == 0)
        sfRenderWindow_drawSprite(smenu->win, smenu->save_on.sprite, NULL);
    else
        sfRenderWindow_drawSprite(smenu->win, smenu->save_off.sprite, NULL);
    if (smenu->htp_off.boulen_button == 0)
        sfRenderWindow_drawSprite(smenu->win, smenu->htp_on.sprite, NULL);
    else
        sfRenderWindow_drawSprite(smenu->win, smenu->htp_off.sprite, NULL);
    if (smenu->quit_off.boulen_button == 0)
        sfRenderWindow_drawSprite(smenu->win, smenu->quit_on.sprite, NULL);
    else
        sfRenderWindow_drawSprite(smenu->win, smenu->quit_off.sprite, NULL);
}

void menu_loop(smenu_t *smenu)
{
    while (sfRenderWindow_pollEvent(smenu->win, &smenu->event)) {
        open_close_events(&smenu->event, smenu->win);
        init_button_play(smenu);
        init_button_save(smenu);
        init_button_quit(smenu);
        init_button_how_to_play(smenu);
    }
    move_parallax(smenu);
    sfRenderWindow_clear(smenu->win, sfBlack);
    sfRenderWindow_drawSprite(smenu->win, smenu->sky.sprite, NULL);
    draw_parallax(smenu);
    display_button(smenu);
    sfRenderWindow_display(smenu->win);
}