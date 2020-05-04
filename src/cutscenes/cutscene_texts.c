/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** cutscene_texts.c
*/

#include "rpg.h"

void start_text(rpg_t *rpg, float seconds)
{
    char *text1 = "Your friend will tell you what to do! (SPACE to interact)";
    char *text2 = "Left Click to attack, ZQSD to move. \
Go save your son!";

    if (seconds > 2)
        sfText_setString(rpg->text.stc, "You must find him before trouble!");
    if (seconds > 4)
        sfText_setString(rpg->text.stc, text1);
    if (seconds > 6)
        sfText_setString(rpg->text.stc, text2);
}

void end_text(rpg_t *rpg, float seconds)
{
    if (seconds < 2)
        sfText_setString(rpg->text.stc, "You DARE try to get him back!");
    if (seconds > 2)
        sfText_setString(rpg->text.stc, "You shall know my wrath then!");
    if (seconds > 4)
        sfText_setString(rpg->text.stc, "Prepare to be destroyed!");
}

void final_text(rpg_t *rpg, float seconds)
{
    char *text = "You saved your son! Evil Jesus is no more!";

    if (seconds < 3)
        sfText_setString(rpg->text.stc, text);
    text = "He descends from the sky where he was held to reunite with you!";
    if (seconds > 3)
        sfText_setString(rpg->text.stc, text);
    text = "You shall both gladly be on your way now!";
    if (seconds > 6)
        sfText_setString(rpg->text.stc, text);
}