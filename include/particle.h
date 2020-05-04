/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** particle.h
*/

#ifndef PARTICLE_H_
    #define PARTICLE_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <math.h>
    #include <stdlib.h>
    #include <stdbool.h>

    #define PI (3.14159265f)
    #define AMPLITUDE (15)
    #define RADIANS(ANGLE) ((ANGLE * PI) / 180)
    #define DEGREES(ANGLE) ((ANGLE * 180 / PI))
    #define GRAVITY_X (1.0f * 0)
    #define GRAVITY_Y (1.0f * 0)
    #define ALPHA (10)

    #define PARTICLE_MAX (5000)
    #define SPEED (20.0f)
    #define LIMIT (150)
    #define PARTICLE_COLOR ((sfColor){140, 223, 255, 150})

    typedef struct particle_environment_s particle_environment_t;
    typedef struct particle_s particle_t;

    struct particle_s
    {
        sfVector2f pos;
        sfVector2f targ;
        sfVector2f vel;
        sfColor color;
        sfVector2f radius;
        int rotation;
        bool living;
    };

    struct particle_environment_s
    {
        float angle_min;
        float angle_max;
        float speed;
        sfVector2f gravity;
        sfUint8 alpha;
        sfClock *clock;
        sfRectangleShape *shape;
    };

    void init_particle_environment(particle_environment_t *,\
    const sfVector2f gravity, const sfUint8 alpha);
    void init_particle(const particle_environment_t *,\
    particle_t *, const sfVector2f pos, sfVector2f targ);
    void display_particle(sfRenderWindow *, const particle_t *,\
    sfRectangleShape *shape);
    void update_particle(const particle_environment_t *, particle_t *);
    void add_particle(const particle_environment_t *, particle_t *,\
    const sfVector2f pos, sfVector2f targ);
    void add_square(const particle_environment_t *particle_environment, \
    particle_t *particle, const sfVector2f pos);

#endif