#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#define MAX_LENGTH_SNAKE 100
#define WIDTH 20
#define HEIGHT 20
#define MAX_FRUITS 1

extern char board[WIDTH][HEIGHT];

extern char snake;

extern char food;

extern char keyboard;

extern int score;

extern char input;

extern int snake_x;
extern int snake_y;

extern int old_x;
extern int old_y;

extern int old_food_x;
extern int old_food_y;

extern int snake_length;

extern int glasses;

#endif