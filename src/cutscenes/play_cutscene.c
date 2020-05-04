/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** play_cutscene.c
*/

#include "rpg.h"

int create_softest(rpg_t *rpg)
{
    char *path_to_lama = "assets/sprites/softest.png";

    rpg->softest = malloc(sizeof(lama_t));
    rpg->softest->texture = sfTexture_createFromFile(path_to_lama, NULL);
    if (!rpg->softest->texture) {
        write(2, "softest spritesheet not found\n", 29);
        return (84);
    }
    rpg->softest->sprite = sfSprite_create();
    sfSprite_setScale(rpg->softest->sprite, (sfVector2f){2, 2});
    sfSprite_setTexture(rpg->softest->sprite, rpg->softest->texture, sfTrue);
    rpg->softest->pos.x = 960;
    rpg->softest->pos.y = -50;
    rpg->softest->size.x = 1.3;
    rpg->softest->size.y = 1.3;
    sfSprite_setScale(rpg->softest->sprite, rpg->softest->size);
    sfSprite_setPosition(rpg->softest->sprite, rpg->softest->pos);
    return (0);
}

void start_cutscene(rpg_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->game_clock);
    float seconds = sfTime_asSeconds(time);

    start_text(rpg, seconds);
    if (seconds < 1.5)
        return (move_player_right(rpg));
    if (seconds < 2)
        return (move_player_down(rpg));
    if (seconds < 2.5)
        return (move_player_up(rpg));
    if (seconds < 3)
        return (move_player_right(rpg));
    if (seconds > 8)
        rpg->cutscenes = sfFalse;
}

void end_cutscene(rpg_t *rpg)
{
    float sec = sfTime_asSeconds(sfClock_getElapsedTime(rpg->game_clock));

    end_text(rpg, sec);
    if (sec < 1)
        move_player_right(rpg);
    if (sec > 6)
        rpg->cutscenes = sfFalse;
}

void final_cutscene(rpg_t *rpg)
{
    float sec = sfTime_asSeconds(sfClock_getElapsedTime(rpg->game_clock));

    final_text(rpg, sec);
    rpg->softest->pos.y += rpg->softest->pos.y > HEIGHT / 2 ? 0 : 2;
    if (sec > 8) {
        rpg->cutscenes = sfFalse;
        rpg->scene = END;
        rpg->softest->pos.x = 960;
        rpg->softest->pos.y = -50;
    }
}

void play_cutscene(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event))
        cutscene_events(rpg);
    if (rpg->lvl == 0) {
        start_cutscene(rpg);
    } else if (rpg->lvl == 6 && !rpg->game_end)
        end_cutscene(rpg);
    if (rpg->lvl == 6 && rpg->game_end)
        final_cutscene(rpg);
    sfSprite_setPosition(rpg->player->sprite, rpg->player->pos);
    sfSprite_setPosition(rpg->softest->sprite, rpg->softest->pos);
    display(rpg);
}