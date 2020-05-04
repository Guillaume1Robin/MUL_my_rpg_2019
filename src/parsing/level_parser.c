/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** level_parser.c
*/

#include "rpg.h"

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
        ptr_message("Getline failed\n", NULL, 2, line);
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
        return (ptr_message("fopen failed\n", NULL, 2, NULL));
    level->collisions = fcollision_parser(file);
    if (getline(&line, &len_line, file) <= 0)
        return (ptr_message("Getline failed\n", NULL, 2, line));
    level->nb_enemies = my_getnbr(line);
    free(line);
    level->enemies = load_enemies(file, level->nb_enemies);
    if (!level->enemies)
        return (ptr_message("enemy loading failed\n", NULL, 2, NULL));
    load_positions(level, file);
    fclose(file);
    return (level);
}