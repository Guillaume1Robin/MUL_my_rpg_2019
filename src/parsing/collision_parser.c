/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** parser.c
*/

#include "rpg.h"

char **check_line(int width, int height, char *ln)
{
    char **sep_line = NULL;

    for (int i = 0; ln[i]; i++)
        if ((ln[i] < '0' || ln[i] > '9') && ln[i] != ' ' && ln[i] != '\n') {
            write(2, "Invalid file\n", 13);
            return (NULL);
        }
    sep_line = my_word_array(ln);
    if ((int)array_len(sep_line) != width * height) {
        free_array(sep_line);
        write(2, "Invalid file\n", 13);
        return (NULL);
    }
    return (sep_line);
}

int **fill_table(int width, int height, char **sep_line)
{
    int **tab = malloc(sizeof(int *) * (height + 1));
    int n = 0;

    tab[height] = NULL;
    for (int y = 0; y < height; y++) {
        tab[y] = malloc(sizeof(int) * (width + 1));
        tab[y][width] = -1;
        for (int x = 0; x < width && sep_line[n]; x++)
            tab[y][x] = my_getnbr(sep_line[n++]);
    }
    free_array(sep_line);
    return (tab);
}

int **parse_file(int width, int height, FILE *file)
{
    char **sep_line = NULL;
    char *line = NULL;
    size_t n = 0;

    if (getline(&line, &n, file) <= 0) {
        free(line);
        return (NULL);
    }
    sep_line = check_line(width, height, line);
    free(line);
    if (!sep_line)
        return (NULL);
    return (fill_table(width, height, sep_line));
}

/*
* Parses a file obtained by treating a jsonized tiled map trough parse.py but already opened
* Returns a **int NULL-terminated on success.
* Each line of the array ends with (-1) so that it is easier to browse.
* Returns NULL on failure and writes on stderr the corresponding message.
*/
int **fcollision_parser(FILE *file)
{
    size_t n = 0;
    char *line = NULL;
    char **sline = NULL;
    int **tab = NULL;

    if (getline(&line, &n, file) <= 0) {
        free(line);
        write(2, "Getline failed\n", 15);
        return (NULL);
    }
    sline = my_word_array(line);
    if (wrong_line_test(sline, line))
        return (NULL);
    free(line);
    tab = parse_file(my_getnbr(sline[0]), my_getnbr(sline[1]), file);
    free_array(sline);
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
    int **tab = NULL;

    if (!file) {
        write(2, "Map file not found", 18);
        return (NULL);
    }
    fclose(file);
    return (tab);
}