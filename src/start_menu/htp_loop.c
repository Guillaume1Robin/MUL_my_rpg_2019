/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** htp_loop.c
*/

#include "rpg.h"

char *htp_text(int which)
{
    char *stry = "Quechua's revenge:\n\n\tAfter the great cleansing, only the \
worthy remained.\n\tYou, the great Quechua were living peacefully with \
your son, \"MNnnNhhn\"(lamas aren't good with names) \n\tsaid to be \
\"the softest\".\n\tHOWEVER, Good times couldn't last.\n\n\
EVIL JESUS, jealous of \"the softest\" soft softness, and enraged \
by the thought that anything \nmight be more lucious than his hair, kidnapped \
your pride and joy.\n\n\tTime to get him back.";
    char *htp = "HOW TO PLAY:\n\n\t-Use your mouse to look around and aim.\t\t\
\t\t\t-Use your left mouse button to spit and attack enemies.\n\t-Use the ARRO\
W keys or ZQSD to jump around.\t\t   -Use I to access the inventory\n\t-Use SP\
ACE to interact, ESCAPE to go back\n\n\t-Use your might and skill to sa\
ve your son!";
    if (which == 0)
        return (stry);
    else
        return (htp);
}

void htp_loop(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->smenu->win, &rpg->smenu->event)) {
        if (rpg->smenu->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            rpg->scene = MENU;
        update_button_return(rpg);
    }
    update_animation(rpg->smenu);
    sfRenderWindow_clear(rpg->smenu->win, sfBlack);
    sfRenderWindow_drawSprite(rpg->window, rpg->smenu->bg_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->smenu->boat_sprite, NULL);
    draw_text_box(rpg->window, rpg->htp);
    draw_text_box(rpg->window, rpg->stry);
    sfRenderWindow_display(rpg->smenu->win);
}
