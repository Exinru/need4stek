/*
** EPITECH PROJECT, 2023
** n4s
** File description:
** get info lidar
*/

#include "../include/cars.h"
#include <stdio.h>

void init_cars(cars_t *cars)
{
    cars->drive.direction = 0;
    cars->drive.speed = 0;
    cars->wheel.wheel_dir = 0;
    cars->wheel.direction = 0;
    cars->sensor.left = 0;
    cars->sensor.semi_left = 0;
    cars->sensor.right = 0;
    cars->sensor.semi_right = 0;
    cars->sensor.center = 0;
    cars->turns = 0;
}

int command_status(char const *status)
{
    if (strcmp(status, "OK") == 0)
        return SUCCESS;
    else
        return ERROR;
}

static void add_sensors(sensor_t *sensor, char **values)
{
    sensor->right = atof(values[3]);
    sensor->semi_right = atof(values[11]);
    sensor->center = atof(values[19]);
    sensor->semi_left = atof(values[27]);
    sensor->left = atof(values[34]);
}

int check_lap(char const *status)
{
    if (strcmp(status, "Track Cleared") == 0)
        return 1;
    return 0;
}

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    if (array != NULL)
        free(array);
    return;
}

//this function is used for getting the sensors and parsing
//them into the sensor struct
void get_info_lidar(cars_t *cars)
{
    size_t size = 0;
    char *buffer = malloc(sizeof(char) * 310);
    char **information = NULL;

    dprintf(1, "GET_INFO_LIDAR\n");
    if (getline(&buffer, &size, stdin) != -1) {
        information = my_str_to_word_array(buffer, ":");
        if (information[1] != NULL && command_status(information[1]) == 0) {
            add_sensors(&cars->sensor, information);
            read_results(cars, information[35]);
        }
    }
    free(buffer);
    free_array(information);
    return;
}
