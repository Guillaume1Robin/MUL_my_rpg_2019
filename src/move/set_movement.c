/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** set_movement.c
*/

#include "rpg.h"

void set_movement(rpg_t *rpg)
{
    int mv = 0;

    rpg->mv[0] = sfKeyboard_isKeyPressed(sfKeyZ) ? 1 : 0;
    rpg->mv[1] = sfKeyboard_isKeyPressed(sfKeyS) ? 1 : 0;
    rpg->mv[2] = sfKeyboard_isKeyPressed(sfKeyQ) ? 1 : 0;
    rpg->mv[3] = sfKeyboard_isKeyPressed(sfKeyD) ? 1 : 0;
    for (int i = 0; i < 4; i++)
        if (rpg->mv[i]) {
            mv = 1;
            break;
        }
    rpg->mv[4] = !mv;
}