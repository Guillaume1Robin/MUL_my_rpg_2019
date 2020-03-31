/*
** EPITECH PROJECT, 2019
** bootstrap_world
** File description:
** array_len.c
*/

#include <stdlib.h>

size_t array_len(void *array)
{
    size_t len = 0;
    void **ari_array = (void **)array;

    if (!ari_array)
        return (0);
    while (ari_array[len])
        len++;
    return (len);
}