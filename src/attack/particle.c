/*
** EPITECH PROJECT, 2020
** particle
** File description:
** particle
*/

#include "particle.h"

void init_particle_environment(particle_environment_t *particle_environment, \
const sfVector2f gravity, const sfUint8 alpha)
{
    sfRectangleShape *particle = sfRectangleShape_create();

    particle_environment->gravity = gravity;
    particle_environment->alpha = alpha;
    particle_environment->shape = particle;
    particle_environment->speed = SPEED;
}

void init_particle(const particle_environment_t *particle_environment, \
particle_t *particle, sfVector2f pos, sfVector2f targ)
{
    sfVector2f delta = {pos.x - targ.x, pos.y - targ.y};
    int variation = (rand() % (AMPLITUDE * 2) - AMPLITUDE);
    float angle = atan2f(delta.y, delta.x) + RADIANS(variation) + PI;
    float speed = ((float)rand()/(float)(RAND_MAX)) * particle_environment->\
speed;

    particle->vel.x = cos(angle) * speed;
    particle->vel.y = sin(angle) * speed;
    particle->pos = pos;
    particle->targ = targ;
    particle->color = PARTICLE_COLOR;
    particle->color.a = rand() % 225 + 30;
    particle->living = true;
    particle->radius.x = 4;
    particle->radius.y = 12;
    particle->rotation = angle * 180 / PI + 90;
}

void display_particle(sfRenderWindow *window, const particle_t *particle, \
sfRectangleShape *circle_shape)
{
    if (particle->living == true) {
        sfRectangleShape_setPosition(circle_shape, particle->pos);
        sfRectangleShape_setSize(circle_shape, particle->radius);
        sfRectangleShape_setFillColor(circle_shape, particle->color);
        sfRectangleShape_setRotation(circle_shape, particle->rotation);
        sfRenderWindow_drawRectangleShape(window, circle_shape, NULL);
    }
}

void update_particle(const particle_environment_t *particle_environment, \
particle_t *particle)
{
    if (particle->living == true) {
        particle->color.a -= particle_environment->alpha;
        particle->vel.x += particle_environment->gravity.x;
        particle->vel.y += particle_environment->gravity.y;
        particle->pos.x += particle->vel.x;
        particle->pos.y += particle->vel.y;
        if (particle->color.a <= LIMIT)
            particle->living = false;
    }
}

void add_particle(const particle_environment_t *particle_environment, \
particle_t *particle, const sfVector2f pos, sfVector2f targ)
{
    int n = 200;

    for (unsigned int i = 0; i < PARTICLE_MAX && n > 0; i += 1) {
        if (particle[i].living == false) {
            init_particle(particle_environment, &particle[i], pos, targ);
            n -= 1;
        }
    }
}