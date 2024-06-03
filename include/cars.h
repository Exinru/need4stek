/*
** EPITECH PROJECT, 2024
** n4s
** File description:
** cars.h
*/
#ifndef CARS_H_
    #define CARS_H_
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <errno.h>
    #include <stddef.h>
    #include <sys/wait.h>
    #include <string.h>

    #define ERROR -1
    #define FAIL 84
    #define SUCCESS 0

typedef struct sensor {
    float right; // the 0 sensor
    float left; // the 32 sensor
    float center; // the 16~ sensor
    float semi_right; // the 8 sensor
    float semi_left; // the 24 sensor
} sensor_t;

typedef struct wheel {
    float wheel_dir; // angulo con el que esta el wheel
    int direction; // 1 izquierda -1 derecha
} wheel_t;

typedef struct drive {
    float speed; //velocidad a la que va
    int direction; // 1 para forward, -1 para backward
} drive_t;

typedef struct cars_data {
    wheel_t wheel;
    drive_t drive;
    sensor_t sensor;
    int turns; //when the lap is done
} cars_t;

int simulator(cars_t *cars);
void stop_simulation(cars_t *cars);
void get_info_lidar(cars_t *cars);
int check_command(char *status);
void read_results(cars_t *cars, char *input);

void change_speed(cars_t *cars, float speed);
void speed_management(cars_t *cars);
void wheel_management(cars_t *cars);

void init_cars(cars_t *cars);
char **my_str_to_word_array(char *str, char *delim);
void free_array(char **array);
#endif
