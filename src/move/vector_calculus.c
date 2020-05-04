/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** vector_calculus.c
*/

#include <SFML/Graphics.h>

/*
Performs the requested operation on the vector:
    * op == '+' adds the coordinates of the vectors;
    * op == '-' substracts b from a;
    * op == '*' scales by multiplication the coordinates;
    * op == '/' divides a's coordinates by b's coordinates;
    * op == '%' applies "modulo b's coordinates" to a's coordinates;
    * default returns (sfVector2f){0, 0};
*/
sfVector2f vec_op(sfVector2f a, sfVector2f b, char op)
{
    switch (op) {
    case '+':
        return ((sfVector2f){a.x + b.x, a.y + b.y});
    case '-':
        return ((sfVector2f){a.x - b.x, a.y - b.y});
    case '*':
        return ((sfVector2f){a.x * b.x, a.y * b.y});
    case '/':
        return ((sfVector2f){a.x / b.x, a.y / b.y});
    case '%':
        return ((sfVector2f){(int)a.x % (int)b.x, (int)a.y % (int)b.y});
    default:
        return ((sfVector2f){0, 0});
    }
}

sfVector2f to_fvec(sfVector2i vec)
{
    return ((sfVector2f){(float)vec.x, (float)vec.y});
}

sfVector2i to_ivec(sfVector2f vec)
{
    return ((sfVector2i){(int)vec.x, (int)vec.y});
}

float square_dist(sfVector2f a, sfVector2f b)
{
    return (((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
}