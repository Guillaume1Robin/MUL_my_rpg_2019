/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** ptr_message.c
*/

#include <stdlib.h>
#include <unistd.h>

void *ptr_message(char const *mess, void *ptr, int fd, void *to_free)
{
    size_t len = 0;

    for (; mess[len]; len++);
    if (to_free)
        free(to_free);
    if (write(fd, mess, len) == -1) {
        write(2, "Write error\n", 12);
        return (NULL);
    }
    return (ptr);
}