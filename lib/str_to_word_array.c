/*
** EPITECH PROJECT, 2023
** n4s
** File description:
** str_to_word_array
*/

#include "../include/cars.h"

void end_enter(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' && str[i + 1] == '\0')
            str[i] = '\0';
    }
}

int countwords(char *str, char *delim)
{
    int cont = 0;
    char *cpy = strdup(str);

    for (char *token = strtok(cpy, delim);
        token != NULL; token = strtok(NULL, delim))
        cont++;
    free(cpy);
    return cont;
}

char **my_str_to_word_array(char *str, char *delim)
{
    char *cpy = strdup(str);
    int num_words = countwords(str, delim);
    char **words = malloc(sizeof(char *) * (num_words + 1));
    int cont = 0;

    if (words == NULL) {
        free(cpy);
        return NULL;
    }
    for (char *token = strtok(cpy, delim);
        token != NULL; token = strtok(NULL, delim)) {
        words[cont] = strdup(token);
        end_enter(words[cont]);
        cont++;
    }
    words[num_words] = NULL;
    free(cpy);
    return words;
}
