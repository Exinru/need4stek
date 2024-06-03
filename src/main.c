/*
** EPITECH PROJECT, 2024
** need4stek
** File description:
** main funct
*/

#include "../include/cars.h"

int main(void)
{
    cars_t *cars = malloc(sizeof(cars_t));

    init_cars(cars);
    simulator(cars);
    return SUCCESS;
}
