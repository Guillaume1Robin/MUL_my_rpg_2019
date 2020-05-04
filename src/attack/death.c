/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** death.c
*/

#include "rpg.h"

void init_square(const particle_environment_t *particle_environment, \
particle_t *particule, const sfVector2f pos)
{
    float angle = ((float)rand()/(float)(RAND_MAX)) * 2 * PI;
    float speed = ((float)rand()/(float)(RAND_MAX)) * \
    particle_environment->speed;

    particule->vel.x = cos(angle) * ((float)rand()/(float)(RAND_MAX)) * speed;
    particule->vel.y = sin(angle) * ((float)rand()/(float)(RAND_MAX)) * speed;
    particule->pos = pos;
    particule->color.a = (rand() % 125) + 130;
    particule->color.r = (rand()% 150) + 100;
    particule->color.g = rand() % 25;
    particule->color.b = rand() % 25;
    particule->living = true;
    particule->radius.x = 5;
    particule->radius.y = 5;
    particule->rotation = rand() % 255;
}

void add_square(const particle_environment_t *particle_environment, \
particle_t *particle, const sfVector2f pos)
{
    int n = 2;

    for (unsigned int i = 0; i < PARTICLE_MAX && n > 0; i += 1) {
        if (particle[i].living == false) {
            init_square(particle_environment, &particle[i], pos);
            n -= 1;
        }
    }
}