/**
 * @file        tic_tac_toe.c
 *
 * @brief       Tic tac toe main 
 *
 * @Author	    Zain Ijaz
 *
 * @Occupation	Software Engineer
 */

/*
 * These materials are provided under license by UEI.
 * UEI licenses this file to you under the SOFTWARE EVALUATION LICENSE AGREEMENT
 * accompanying the SDK delivered to you (the "License").
 * You may also obtain a copy of the License directly from UEI.
 * You may not use this file except in strict compliance with the License
 * and all restrictions set forth therein. Your use and access to the file
 * constitutes your agreement to be bound by the terms of the License.
 * Unless required by applicable law or agreed to in writing, all materials
 * distributed under the License is provided on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, either express or implied.
 */

#include<stdio.h>
#include<stdlib.h>
/*
 ********************************************************************************
 * Constants.
 ********************************************************************************
 */

#define     MAZE_MAX    9
#define     ROWS_MAX    3
#define     COLS_MAX    3
/*
 ********************************************************************************
 * Globals
 ********************************************************************************
 */

/*
 ********************************************************************************
 * Prototypes.
 ********************************************************************************
*/


void tic_tac_create_maze(char*** maze);
void tic_tac_print_maze(char** func_maze);
void tic_tac_destroy_maze(char** maze);
void tic_tac_set_maze_values (char ***maze, int x, int y, char value);
void tic_tac_arrow_key();

int main( int argc, char *argv[] )
{
    char **maze_ptr = NULL;
    while(1)
    {
        tic_tac_arrow_key();
    }

    tic_tac_create_maze(&maze_ptr);
    tic_tac_print_maze(maze_ptr);


    tic_tac_set_maze_values(&maze_ptr, 0,1,'X');

    tic_tac_print_maze(maze_ptr);

    tic_tac_destroy_maze(maze_ptr);

    return 0;
}


void tic_tac_arrow_key()
{

    if (getchar() == '\033') 
    { // if the first value is esc
        getchar(); // skip the [
        switch(getchar()) 
        { // the real value
            case 'A':
                printf("Up\n");// code for arrow up
                break;
            case 'B':
                printf("Down\n");// code for arrow down
                break;
            case 'C':
                printf("Right\n");// code for arrow right
                break;
            case 'D':
                printf("Left\n");// code for arrow left
                break;
        }
    }
}

void tic_tac_print_menu()
{
    printf("*****************************************************\n");
    printf("*********** Welcome to Tic Tac Toe ******************\n");
    printf("*****************************************************\n");


    printf("Start Game:\t\t1\n"); 
    printf("Help:\t\t?\n");
    printf("\n");
}

void tic_tac_create_maze(char*** maze)
{
    int i,j;

    char **tmp = (char **)calloc(ROWS_MAX, sizeof(char *));

    for(i=0;i<COLS_MAX;i++)
    {
        tmp[i] = (char *)calloc(COLS_MAX , sizeof(char));
    }

    for(i=0;i<COLS_MAX;i++)
    {
        for(j=0;j<ROWS_MAX;j++)
        {
            tmp[i][j] = '-';
        } 
    }
    *maze = tmp;
} 

void tic_tac_destroy_maze(char** maze)
{
    int i;

    for(i=0;i<COLS_MAX;i++)
    {
            free(maze[i]);
    }

    free(maze);
}

void tic_tac_print_maze(char **func_maze)
{
    int in_x, in_y;

    for( in_x=0; in_x < ROWS_MAX; in_x++)
    {
        printf("\n");
        for(in_y=0;in_y< COLS_MAX;in_y++)
        {
            printf("%c\t", func_maze[in_x][in_y]);
            
        }
    }
    printf("\n");
}


void tic_tac_set_maze_values (char ***maze, int x, int y, char value)
{
    if(value == 'X' || value == 'O')
        *maze[x][y] = value;
}


//Return value from each function and write doxygen comments about each function
//Create a header file with all the definiations and another header file with all the function prototypes. 
//Create a new thread that keeps looking at the game combination and use mutex to sychronize data. 
//Create a library for the tictactoe.so and link it to the application






















