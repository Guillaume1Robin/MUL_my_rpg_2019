/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** level_parser_two.c
*/

#include "rpg.h"

static sfBool (*ld_en_percs[5])(enemy_t *) =
{
    [BAT] = &get_bat_percs,
    [SLUG] = &get_slug_percs,
    [EGG] = &get_egg_percs,
    [MINIBOSS] = &get_miniboss_percs,
    [BOSS] = &get_boss_percs
};

sfBool fill_enemy_struct(enemy_t *enemy, char *info)
{
    char **tmp = my_sep_array(info, ':');

    if (array_len(tmp) != 3)
        return (sfFalse);
    enemy->type = my_getnbr(tmp[0]);
    enemy->start_pos.x = (float)my_getnbr(tmp[1]);
    enemy->start_pos.y = (float)my_getnbr(tmp[2]);
    enemy->pos = enemy->start_pos;
    free_array(tmp);
    if (enemy->type > 5 || enemy->type < 1)
        return (false);
    return (ld_en_percs[enemy->type - 1](enemy));
}

enemy_t **load_enemies(FILE *file, int nb_en)
{
    char *line = NULL;
    size_t len_line = 0;
    char **sline = NULL;
    enemy_t **enemies = malloc(sizeof(enemy_t *) * (nb_en + 1));

    enemies[nb_en] = NULL;
    if (getline(&line, &len_line, file) < 0)
        return (ptr_message("Getline failed\n", NULL, 2, line));
    sline = my_word_array(line);
    free(line);
    for (int i = 0; nb_en && sline && sline[i]; i++) {
        enemies[i] = malloc(sizeof(enemy_t));
        if (!enemies[i] || !fill_enemy_struct(enemies[i], sline[i]))
            return (NULL);
    }
    if (sline)
        free_array(sline);
    return (enemies);
}