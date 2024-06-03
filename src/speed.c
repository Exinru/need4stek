/*
** EPITECH PROJECT, 2024
** n4s
** File description:
** simulator.c
*/
#include "../include/cars.h"

void change_speed(cars_t *cars, float speed)
{
    char *buffer = malloc(sizeof(char) * 4000);
    size_t size = 0;
    char **information = NULL;

    cars->drive.speed = speed;
    cars->drive.direction = 1;
    dprintf(1, "CAR_FORWARD:%f\n", cars->drive.speed);
    getline(&buffer, &size, stdin);
    information = my_str_to_word_array(buffer, ":");
    if (check_command(information[1]) == 0) {
        read_results(cars, information[3]);
    }
    free_array(information);
    free(buffer);
}

static void speed_management_one(cars_t *cars, float distance)
{
    if (distance <= 100)
        change_speed(cars, 0.10);
    if (distance < 200 && distance > 100)
        change_speed(cars, 0.15);
    if (distance <= 300 && distance > 200)
        change_speed(cars, 0.30);
    if (distance <= 500.0 && distance > 300.0)
        change_speed(cars, 0.40);
}

static void speed_management_two(cars_t *cars, float distance)
{
    speed_management_one(cars, distance);
    if (distance < 500.0 && distance < 700.00)
        change_speed(cars, 0.50);
    if (distance > 700.0 && distance < 1000.0)
        change_speed(cars, 0.60);
    if (distance >= 1000.0 && distance < 2000)
        change_speed(cars, 0.80);
    if (distance >= 2000.0 && distance < 3000.0)
        change_speed(cars, 1);
}

void speed_management(cars_t *cars)
{
    char *buffer = malloc(sizeof(char) * 4000);
    float distance = cars->sensor.center;

    speed_management_two(cars, distance);
    if (distance >= 3000.0) {
        change_speed(cars, 1);
        cars->drive.direction = 1;
    }
    free(buffer);
}
