/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all prototypes of all the lib
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <unistd.h>

    int my_compute_factorial(int nb);

    int my_strlen(char const *str);

    int my_compute_power(int nb, int p);

    int my_compute_square_root(int nb);

    int my_is_prime(int nb);

    int my_find_prime_sup(int nb);

    int my_getnbr(char const *str);

    int my_greatest(int a, int b);

    int my_lowest(int a, int b);

    void my_putchar(char c);

    int my_str_isnum(char const *str);

    void my_put_nbr(int n);

    void my_putstr(char const *str);

    char *my_revstr(char *str);

    int my_show_word_array(char * const *tab);

    void my_sort_int_array(int *tab, int size);

    char *my_strcat(char const *dest, char const *src);

    int my_strcmp(char const *s1, char const *s2);

    char *my_strcpy(char *dest, char const *src);

    char *my_strdup(char const *src);

    char *my_strncat(char *dest, char const *src, int n);

    int my_strncmp(char const *s1, char const *s2, int n);

    char *my_strncpy(char *dest, char const *src, int n);

    void my_swap(int *a, int *b);

    char *my_realloc_str(char *str, int size);

    int my_putnbr_base(long nbr, char const *base);

    int my_printf(char *str, ...);

    char *my_itos(long long nb);

    char *my_append_str(char *str, char c);

    char **my_word_array(char *st);

    char **my_sep_array(char *st, char sep);

    int check_str_empty(char *str);

    size_t array_len(char **array);

    int num_test(char *str);

    void my_exit(char *str, int code);

    int alphanum_test(char *str);

    void free_array(void *array);

    void *ptr_message(char const *mess, void *ptr, int fd, void *to_free);

#endif /*MY_H_ */
