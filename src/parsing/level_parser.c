/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** level_parser.c
*/

#include "rpg.h"

static sfBool (*ld_en_percs[5])(enemy_t *) =
{
    [AIR] = &get_bat_percs,
    [SLUG] = &get_slug_percs,
    [SKELETON] = &get_skeleton_percs,
    [MINIBOSS] = &get_miniboss_percs,
    [BOSS] = &get_boss_percs

};

sfBool fill_enemy_struct(enemy_t *enemy, char *info)
{
    char **tmp = my_sep_array(info, ':');

    if (array_len(tmp) != 3)
        return (sfFalse);
    enemy->type = my_getnbr(tmp[0]) - 1;
    enemy->start_pos.x = (float)my_getnbr(tmp[1]);
    enemy->start_pos.y = (float)my_getnbr(tmp[2]);
    free_array(tmp);
    return (sfTrue);
}

enemy_t **load_enemies(FILE *file, int nb_enemies)
{
    char *line = NULL;
    size_t len_line = 0;
    char **sline = NULL;
    enemy_t **enemies = malloc(sizeof(enemy_t *) * (nb_enemies + 1));

    enemies[nb_enemies] = NULL;
    if (getline(&line, &len_line, file) <= 0) {
        free(line);
        write(2, "Getline failed\n", 15);
        return (NULL);
    }
    sline = my_word_array(line);
    free(line);
    for (int i = 0; sline && sline[i]; i++) {
        enemies[i] = malloc(sizeof(enemy_t));
        if (!fill_enemy_struct(enemies[i], sline[i]))
            return (NULL);
    }
    free_array(sline);
    return (enemies);
}

sfVector2f parse_pos(char *tmp)
{
    char **arr = my_sep_array(tmp, ':');
    sfVector2f pos = {0};


    if (array_len(arr) != 2) {
        free_array(arr);
        return ((sfVector2f){0, 0});
    } else if (!my_strcmp(arr[0], "None") || !my_strcmp(arr[1], "None")) {
        free_array(arr);
        return ((sfVector2f){0, 0});
    }
    pos = (sfVector2f){my_getnbr(arr[0]), my_getnbr(arr[1])};
    free_array(arr);
    return (pos);
}

void load_positions(level_t *level, FILE *file)
{
    char *line = NULL;
    size_t len_line = 0;
    char **sline = NULL;

    if (getline(&line, &len_line, file) <= 0) {
        free(line);
        write(2, "Getline failed\n", 15);
        return;
    }
    sline = my_word_array(line);
    free(line);
    level->merch_pos = parse_pos(sline[0]);
    level->player_start = parse_pos(sline[1]);
    level->player_end = parse_pos(sline[2]);
}

level_t *level_parser(char const *level_path)
{
    level_t *level = malloc(sizeof(level_t));
    FILE *file = fopen(level_path, "r");
    char *line = NULL;
    size_t len_line = 0;

    if (!file)
        return (NULL);
    level->collisions = fcollision_parser(file);
    if (getline(&line, &len_line, file) <= 0) {
        free(line);
        write(2, "Getline failed\n", 15);
        return (NULL);
    }
    level->nb_enemies = my_getnbr(line);
    free(line);
    level->enemies = load_enemies(file, level->nb_enemies);
    if (!level->enemies)
        return (NULL);
    load_positions(level, file);
    fclose(file);
    return (level);
}