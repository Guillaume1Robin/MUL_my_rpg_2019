/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** error_handling.c
*/

#include "rpg.h"

sfBool wrong_line_test(char **sline, char *line)
{
    if (array_len(sline) != 2 || num_test(sline[0]) || num_test(sline[1])) {
        free_array(sline);
        free(line);
        write(2, "Invalid file\n", 13);
        return (sfTrue);
    }
    return (sfFalse);
}