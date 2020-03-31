/*
** EPITECH PROJECT, 2019
** bootstrap_world
** File description:
** my_append_str.c
*/

#include <stdlib.h>

size_t my_strlen(char const *str);

char *my_append_str(char *str, char c)
{
    size_t len = my_strlen(str);
    char *tmp = malloc(sizeof(char) * (len + 2));

    for (int i = 0; str[i]; i++)
        tmp[i] = str[i];
    tmp[len] = c;
    tmp[len + 1] = 0;
    free(str);
    return (tmp);
}