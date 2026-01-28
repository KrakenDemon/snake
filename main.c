#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "gameConfig.h"

int main(void){

    char board[WIDTH][HEIGHT];
    char food = '$';
    char snake = 'O';
    int snake_x[MAX_LENGTH_SNAKE];
    int snake_y[MAX_LENGTH_SNAKE];
    int fruit_x[MAX_FRUITS];
    int fruit_y[MAX_FRUITS];
    int snake_length = 1;
    char input;
    int score = 0;

    srand(time(NULL));

    do
    {

        printf("1. Start\n2. Exit\n");
        scanf("%c", &input);

        if (input == '2')
        {
            printf("Exiting game...\n");
            return 0;
        }

    } while (input != '1');
    
    for (int i = 0; i < WIDTH; ++i)
    {
        for (int j = 0; j < HEIGHT; ++j)
        {
            if (i == 0 || j == 0 || i == WIDTH - 1 || j == HEIGHT - 1)
            {
                board[i][j] = '#';
            }
            else 
            {
                board[i][j] = ' ';
            }
        }
    }

    board[1 + rand() % (WIDTH - 2)][1 + rand() % (HEIGHT - 2)] = food; 

    snake_x[0] = WIDTH / 2;
    snake_y[0] = HEIGHT / 2;
        
    while (1)
    {
        system("cls");
        
        for (int i = 0; i < WIDTH; ++i)
        {
            for (int j = 0; j < HEIGHT; ++j)
            {
                printf("%c", board[i][j]);
            }
            printf("\n");
        }
       
        for (int  i = 0; i < snake_length; ++i)
        {
            board[snake_x[i]][snake_y[i]] = ' ';
        }
        
        board[snake_x[snake_length-1]][snake_y[snake_length-1]] = ' ';
        
        board[snake_x[snake_length-1]][snake_y[snake_length-1]] = ' ';
        
        printf("Exit game? (0)\n");
        printf("Score: %d\n", score);
        printf("Enter a direction (w/a/s/d): ");
        scanf(" %c", &input);
        
        int old_x = snake_x[0];
        int old_y = snake_y[0];
        int temp_x, temp_y;
        
        for (int i = 1; i < snake_length; ++i)
        {
            temp_x = snake_x[i];
            temp_y = snake_y[i];

            snake_x[i] = old_x;
            snake_y[i] = old_y;

            old_x = temp_x;
            old_y = temp_y;
        }        

        switch (input)
        {
            case 'a':
            --snake_y[0];
            break;
            case 'w':
            --snake_x[0];
            break;
            case 'd':
            ++snake_y[0];
            break;
            case 's':
            ++snake_x[0];
            break;
            case '0':
            printf("Exiting games\n");
            return 0;
        }

        for (int i = 1; i < snake_length; ++i)
        {
            if (snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i])
            {
                printf("Game over!");
                return 0;
            }   
        }

        if (board[snake_x[0]][snake_y[0]] == '#')
        {
            printf("Game over!\n");
            return 0;
        }
                
        if (board[snake_x[0]][snake_y[0]] == food)
        {
            if (snake_length < MAX_LENGTH_SNAKE)
            {
                snake_x[snake_length] = snake_x[snake_length - 1];
                snake_y[snake_length] = snake_y[snake_length - 1];
                ++snake_length;
                ++score;
            }

            do {
                fruit_x[0] = 1 + rand() % (WIDTH - 2);
                fruit_y[0] = 1 + rand() % (HEIGHT - 2);
            } while (board[fruit_x[0]][fruit_y[0]] != ' ');

            board[fruit_x[0]][fruit_y[0]] = food;
        }

        for (int i = 0; i < snake_length; ++i)
        {
            board[snake_x[i]][snake_y[i]] = 'O';
        }
    }
    return 0;
}