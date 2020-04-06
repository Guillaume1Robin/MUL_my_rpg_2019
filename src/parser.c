/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** parser.c
*/

#include "rpg.h"

void free_array(void *array)
{
    void **arr = (void **)array;
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(array);
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
    if (!sep_line)
        return (NULL);
    return (fill_table(width, height, sep_line));
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
    if (array_len(sline) != 2 || num_test(sline[0]) || num_test(sline[1])) {
        free_array(sline);
        free(line);
        write(2, "Invalid file\n", 13);
        return (NULL);
    }
    tab = parse_file(my_getnbr(sline[0]), my_getnbr(sline[1]), file);
    fclose(file);
    return (tab);
}