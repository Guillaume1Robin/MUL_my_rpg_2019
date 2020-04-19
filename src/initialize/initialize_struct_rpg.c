/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** initialise_struct_rpg.c
*/

#include "rpg.h"

void initialize_value_struct_rpg(rpg_t *rpg)
{
    rpg->scene = MENU;
    rpg->cutscenes = sfTrue;
    rpg->lvl = 0;
    for (int i = 0; i < 5; i++)
        rpg->mv[i] = 0;
}

void initialize_text_box(text_t *text)
{
    char *path = "assets/sprites/text_box.png";

    text->box_sprite = sfSprite_create();
    text->box_texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(text->box_sprite, text->box_texture, sfTrue);
    sfSprite_setPosition(text->box_sprite, (sfVector2f){80, 890});
    sfSprite_setScale(text->box_sprite, (sfVector2f){4, 1});
    text->font = sfFont_createFromFile("assets/Pixellari.ttf");
    text->stc = sfText_create();
    sfText_setFont(text->stc, text->font);
    sfText_setString(text->stc, "Your son is held captive by monsters! Go get him!");
    sfText_setPosition(text->stc, (sfVector2f){100, 900});
    sfText_setColor(text->stc, sfBlack);
}

int initialize_window(rpg_t *rpg)
{
    sfVideoMode mode = {.width = WIDTH, .height = HEIGHT, .bitsPerPixel = 32};
    char *name = "Quechua's Revenge";

    rpg->window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(rpg->window, 50);
    initialize_text_box(&rpg->text);
    if (!rpg->window || !rpg->text.font  || !rpg->text.box_texture) {
        write(2, "RPG initialization failed\n", 26);
        return (84);
    }
    return (0);
}

int initialize_value_struct(rpg_t *rpg)
{
    initialize_value_struct_rpg(rpg);
    if (initialize_window(rpg) == 84)
        return (84);
    return (0);
}