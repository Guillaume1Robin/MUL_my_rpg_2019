/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** parser.c
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

void free_array(void **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

int isnum(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (1);
    return (0);
}

char **check_line(int width, int height, char *line)
{
    char **sep_line = NULL;
    for (int i = 0; line[i]; i++)
        if ((line[i] < '0' || line[i] > '9') && line[i] != ' ') {
            write(2, "Invalid file\n", 13);
            return (NULL);
        }
    sep_line = my_word_array(line);
    if ((int)array_len(sep_line) != width * height) {
        write(2, "Invalid file\n", 13);
        return (NULL);
    }
    return (sep_line);
}

int **parse_file(int width, int height, FILE *file)
{
    int **tab = NULL;
    char **sep_line = NULL;
    char *line = NULL;
    size_t n = 0;

    if (getline(&line, &n, file) <= 0) {
        free(line);
        return (NULL);
    }
    sep_line = check_line(width, height, line);
    if (!sep_line)
        return (NULL);
    tab = malloc(sizeof(int *) * (height + 1));
    tab[height] = NULL;
    for (int y = 0; y < height && sep_line[n]; y++) {
        tab[y] = malloc(sizeof(int) * (width + 1));
        tab[y][width] = -1;
        for (int x = 0; x < width && sep_line[n]; x++)
            tab[y][x] = my_getnbr(sep_line[n++]);
    }
    return (tab);
}

/*
* Parses a file obtained by treating a jsonized tiled map trough parse.py
* Returns a **int NULL-terminated on success.
* Each line of the array ends with (-1) so that it is easier to browse.
* Returns NULL on failure and writes on stderr the corresponding message.
*/
int **collision_parser(char const *map_path)
{
    FILE *file = fopen(map_path, "r");
    char *line = NULL;
    size_t n = 0;
    char **sline = NULL;
    int **tab = NULL;

    if (getline(&line, &n, file) <= 0) {
        free(line);
        write(2, "Getline failed\n", 15);
        return (NULL);
    }
    sline = my_word_array(line);
    if (array_len(sline) != 2 || isnum(sline[0]) || isnum(sline[1])) {
        free_array((void **)sline);
        free(line);
        write(2, "Invalid file\n", 13);
        return (NULL);
    }
    tab = parse_file(my_getnbr(sline[0]), my_getnbr(sline[1]), file);
    fclose(file);
    return (tab);
}

int main(int argc, char const *argv[])
{
    int **map = collision_parser("./maps/map");

    if (!map)
        return (write(2, "WRONG", 5));
    for (int y = 0; map[y]; y++) {
        for (int x = 0; map[y][x] != -1; x++)
            printf("%d, ", map[y][x]);
        printf("\n");
    }
    return 0;
}
