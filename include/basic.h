/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** basic.h
*/

#ifndef BASIC_H_
    #define BASIC_H_

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include "my.h"

    void open_close_events(sfEvent *event, sfRenderWindow *win);

#endif