/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** intersections.c
*/

#include <SFML/Graphics.h>

float sign(sfVector2f p1, sfVector2f p2, sfVector2f p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

sfBool is_point_in_tri(sfVector2f pt, sfVector2f v1, sfVector2f v2, \
sfVector2f v3)
{
    sfBool b[3];

    b[0] = sign(pt, v1, v2) < 0.0f;
    b[1] = sign(pt, v2, v3) < 0.0f;
    b[2] = sign(pt, v3, v1) < 0.0f;
    return ((b[0] == b[1]) && (b[1] == b[2]));
}

sfBool intersec_rect_tri(sfVector2f const tri[3], sfFloatRect const rect)
{
    sfVector2f shape[4] = {
        {rect.top,               rect.left              },
        {rect.top,               rect.left + rect.width },
        {rect.top + rect.height, rect.left              },
        {rect.top + rect.height, rect.left + rect.width },
    };
    sfBool ret = is_point_in_tri(shape[0], tri[0], tri[1], tri[2]);

    ret = ret || is_point_in_tri(shape[0], tri[0], tri[1], tri[2]);
    ret = ret || is_point_in_tri(shape[0], tri[0], tri[1], tri[2]);
    ret = ret || is_point_in_tri(shape[0], tri[0], tri[1], tri[2]);
    return (ret);
}