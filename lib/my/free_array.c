/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** free_array.c
*/

#include <stdlib.h>

void free_array(void *array)
{
    void **arr = (void **)array;
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(array);
}