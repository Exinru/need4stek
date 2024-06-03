/*
** EPITECH PROJECT, 2023
** n4s
** File description:
** simulator.c
*/

#include "../include/cars.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void change_wheel(cars_t *cars, float wheel_dir, int direction)
{
    char *buffer = malloc(sizeof(char) * 400);
    size_t size = 0;
    char **information = NULL;

    cars->wheel.wheel_dir = wheel_dir;
    cars->wheel.direction = direction;
    dprintf(1, "WHEELS_DIR:%f\n", wheel_dir * direction);
    getline(&buffer, &size, stdin);
    information = my_str_to_word_array(buffer, ":");
    if (check_command(information[1]) == 0) {
        read_results(cars, information[3]);
    }
    free(buffer);
    free_array(information);
    return;
}

void more_wheel_management(cars_t *cars)
{
    int center = cars->sensor.center;

    if (center <= 1200)
        cars->wheel.wheel_dir = 0.15;
    if (center <= 1000)
        cars->wheel.wheel_dir = 0.25;
    if (center <= 800)
        cars->wheel.wheel_dir = 0.30;
    if (center <= 600)
        cars->wheel.wheel_dir = 0.35;
    if (center < 400)
        cars->wheel.wheel_dir = 0.40;
    if (center <= 200)
        cars->wheel.wheel_dir = 0.50;
    if (center <= 100)
        cars->wheel.wheel_dir = 0.60;
    return;
}

void wheel_management(cars_t *cars)
{
    int center = cars->sensor.center;

    if (cars->wheel.wheel_dir != 0 && center > 650.0) {
        cars->wheel.direction = 0;
        cars->wheel.wheel_dir = 0;
        change_speed(cars, 0.15);
        change_wheel(cars, cars->wheel.wheel_dir, cars->wheel.direction);
        return;
    }
    if (cars->sensor.right < cars->sensor.left && center < 1200) {
        cars->wheel.direction = -1;
        change_speed(cars, 0.50);
        more_wheel_management(cars);
    }
    if (cars->sensor.right > cars->sensor.left && center < 1200) {
        cars->wheel.direction = 1;
        change_speed(cars, 0.50);
        more_wheel_management(cars);
    }
    change_wheel(cars, cars->wheel.wheel_dir, cars->wheel.direction);
}
