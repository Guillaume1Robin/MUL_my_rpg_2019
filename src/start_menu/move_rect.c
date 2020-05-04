/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** move_parallax.c
*/

#include "rpg.h"

sfBool move_hrect(sfIntRect *rectangle, int offset, int max_value)
{
    rectangle->left = rectangle->left + offset;
    if (rectangle->left > max_value) {
        rectangle->left = 0;
        return (sfTrue);
    }
    return (sfFalse);
}

sfBool move_vrect(sfIntRect *rectangle, int offset, int max_value)
{
    rectangle->top = rectangle->top + offset;
    if (rectangle->top > max_value) {
        rectangle->top = 0;
        return (sfTrue);
    }
    return (sfFalse);
}