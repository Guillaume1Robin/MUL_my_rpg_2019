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
    rpg->prev_scene = MENU;
    rpg->cutscenes = sfTrue;
    rpg->boss_phases = sfClock_create();
    rpg->bool_npc = 0;
    rpg->check_item = 0;
    rpg->lvl = 0;
    rpg->game_end = false;
    rpg->potion = 0;
    rpg->boots = 0;
    rpg->shield = 0;
    rpg->xp = 0;
    rpg->npc_clock = sfClock_create();
    for (int i = 0; i < 4; i++)
        rpg->en_clock[i] = sfClock_create();
    for (int i = 0; i < 5; i++)
        rpg->mv[i] = 0;
}

void init_text_box(text_t *text, char *txt, sfVector2f pos, sfVector2f scale)
{
    char *path = "assets/sprites/text_box.png";

    text->box_sprite = sfSprite_create();
    text->box_texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(text->box_sprite, text->box_texture, sfTrue);
    sfSprite_setPosition(text->box_sprite, pos);
    sfSprite_setScale(text->box_sprite, scale);
    text->font = sfFont_createFromFile("assets/Pixellari.ttf");
    text->stc = sfText_create();
    sfText_setFont(text->stc, text->font);
    sfText_setString(text->stc, txt);
    sfText_setPosition(text->stc, (sfVector2f){pos.x + 20, pos.y + 10});
    sfText_setColor(text->stc, sfBlack);
}

void init_htp(text_t *text, char *txt, sfVector2f pos, sfVector2f scale)
{
    char *path = "assets/sprites/text_box.png";

    text->box_sprite = sfSprite_create();
    text->box_texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(text->box_sprite, text->box_texture, sfTrue);
    sfSprite_setPosition(text->box_sprite, pos);
    sfSprite_setScale(text->box_sprite, scale);
    text->font = sfFont_createFromFile("assets/Pixellari.ttf");
    text->stc = sfText_create();
    sfText_setFont(text->stc, text->font);
    sfText_setString(text->stc, txt);
    sfText_setPosition(text->stc, (sfVector2f){pos.x + 60, pos.y + 70});
    sfText_setColor(text->stc, sfBlack);
}

int initialize_window(rpg_t *rpg)
{
    sfVideoMode mode = {.width = WIDTH, .height = HEIGHT, .bitsPerPixel = 32};
    char *name = "Quechua's Revenge";
    char *txt = "Your son is held captive by monsters! Go get him!";
    char *htp = htp_text(1);
    char *stry = htp_text(0);

    rpg->window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(rpg->window, 50);
    init_text_box(&rpg->text, txt, (sfVector2f){80, 890}, (sfVector2f){4, 1});
    init_htp(&rpg->stry, stry, (sfVector2f){30, 30}, (sfVector2f){7, 8});
    init_htp(&rpg->htp, htp, (sfVector2f){30, 550}, (sfVector2f){7, 6});
    init_htp(&rpg->end_screen, "END", (sfVector2f){30, 200}, (sfVector2f){7, 6}\
);
    if (!rpg->window || !rpg->text.font  || !rpg->text.box_texture\
    || !rpg->htp.font || !rpg->htp.box_texture) {
        write(2, "RPG initialization failed\n", 26);
        return (84);
    }
    sfRenderWindow_setKeyRepeatEnabled(rpg->window, (sfFalse));
    return (0);
}

int init_rpg(rpg_t *rpg)
{
    char *title = "assets/sprites/title.png";
    sfVector2f mid_screen = {(WIDTH / 2) - 300, 20};

    srand(time(NULL));
    init_music(rpg);
    rpg->levels = create_game_layout(NB_LEVELS);
    initialize_value_struct_rpg(rpg);
    if (!rpg->music || !rpg->levels || initialize_window(rpg) == 84)
        return (sfFalse);
    rpg->title.sprite = sfSprite_create();
    rpg->title.texture = sfTexture_createFromFile(title, NULL);
    sfSprite_setTexture(rpg->title.sprite, rpg->title.texture, sfFalse);
    sfSprite_setPosition(rpg->title.sprite, mid_screen);
    sfSprite_setScale(rpg->title.sprite, (sfVector2f){4, 4});
    create_objects_sprites(rpg);
    create_box_hp(rpg);
    create_text_hp(rpg);
    create_nb_hp(rpg);
    return (create(rpg));
}