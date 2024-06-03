/*
** EPITECH PROJECT, 2023
** n4s
** File description:
** get info lidar
*/

#include "../include/cars.h"

void read_results(cars_t *cars, char *input)
{
    if (strcmp(input, "Track Cleared") == 0) {
        cars->turns = 1;
        stop_simulation(cars);
    }
}

int check_command(char *status)
{
    if (strcmp(status, "OK") == 0)
        return 0;
    else
        return 1;
}

static void start_simulation(cars_t *cars)
{
    size_t size = 0;
    char *buffer = malloc(sizeof(char) * 4000);
    char **information = NULL;

    dprintf(1, "START_SIMULATION\n");
    getline(&buffer, &size, stdin);
    information = my_str_to_word_array(buffer, ":");
    if (check_command(information[1]) == 1)
        start_simulation(cars);
    free_array(information);
    free(buffer);
}

void stop_simulation(cars_t *cars)
{
    size_t size = 0;
    char *buffer = malloc(sizeof(char) * 100000);

    free(cars);
    dprintf(1, "STOP_SIMULATION\n");
    getline(&buffer, &size, stdin);
    dprintf(2, "%s", buffer);
    free(buffer);
    exit(0);
}

void manage_car(cars_t *cars)
{
    if (cars->turns == 0) {
        wheel_management(cars);
        speed_management(cars);
    }
    return;
}

int simulator(cars_t *cars)
{
    start_simulation(cars);
    while (1) {
        get_info_lidar(cars);
        manage_car(cars);
    }
    return SUCCESS;
}
