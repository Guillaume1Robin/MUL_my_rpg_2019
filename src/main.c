/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main.c
*/

#include "rpg.h"

int main(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    int **map = collision_parser("map");

    int i = 0;
    int j = 0;

    while (map[i] != NULL) {
        while (map[i][j] != -1) {
            printf("%d", map[i][j]);
            j += 1;
        }
        printf("\n");
        j = 0;
        i += 1;
    }

    if (!initialise_value_struct(rpg))
    create(rpg);
    open_window(rpg);
    free(rpg);
}
