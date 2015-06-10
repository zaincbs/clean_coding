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
 * These materials are provided under license by RX EMBEDDED.
 * RX EMBEDDED licenses this file to you under the SOFTWARE EVALUATION LICENSE AGREEMENT
 * accompanying the SDK delivered to you (the "License").
 * You may also obtain a copy of the License directly from RX EMBEDDED.
 * You may not use this file except in strict compliance with the License
 * and all restrictions set forth therein. Your use and access to the file
 * constitutes your agreement to be bound by the terms of the License.
 * Unless required by applicable law or agreed to in writing, all materials
 * distributed under the License is provided on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, either express or implied.
 */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <errno.h>
#include "tic_tac_toe.h"
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
int tic_tac_toe_start(void);
void tic_tac_toe_get_indexes(char **maze_for_check, int *x, int *y);



int main( int argc, char *argv[] )
{
    system("clear");

    tic_tac_toe_start();

    return 0;
}


int tic_tac_toe_start(void)
{
    char **maze_ptr = NULL;
    int x_x, y_y;

    tic_tac_print_menu();

    maze_ptr = tic_tac_create_maze(); //error checking
    
    tic_tac_set_maze_values(maze_ptr, 0, 0, 'X');
    tic_tac_set_maze_values(maze_ptr, 0, 2, 'X');
    tic_tac_set_maze_values(maze_ptr, 1, 2, 'X');


    tic_tac_toe_get_indexes(maze_ptr, &x_x, &y_y);

    tic_tac_destroy_maze(maze_ptr);

    return 0;
}

void tic_tac_toe_get_indexes(char **maze_for_check, int *x, int *y)
{
    int x_axis= 1;
    int y_axis= 1;
    int key_press;    
    int ret;
    char old_value = '-';
    int old_x = 1;
    int old_y = 1; 

    tic_tac_print_maze(maze_for_check); 
    while(key_press != TIC_ENTER)
    {
        printf("Use Arrow Keys to select your marking Position:\n");
        
        tic_tac_print_maze(maze_for_check); 

        key_press = tic_tac_arrow_key();
        
        old_x = x_axis;
        old_y = y_axis;

        switch(key_press)
        {
            case TIC_RIGHT:
                tic_tac_set_maze_values(maze_for_check, old_x, old_y, old_value);
                old_value = maze_for_check[old_x][old_y];
                y_axis++;
                break;
            case TIC_LEFT:
                tic_tac_set_maze_values(maze_for_check, old_x, old_y, old_value);
                old_value = maze_for_check[old_x][old_y];
                y_axis--;
                break;
            case TIC_UP:
                tic_tac_set_maze_values(maze_for_check, old_x, old_y, old_value);
                old_value = maze_for_check[old_x][old_y];
                x_axis--;
                break;
            case TIC_DOWN:
                tic_tac_set_maze_values(maze_for_check, old_x, old_y, old_value);
                old_value = maze_for_check[old_x][old_y];
                x_axis++;
                break;
            case TIC_ENTER:
                *x = x_axis;
                *y = y_axis;
                break;
        } 

        if(x_axis > 2)
            x_axis = 2;
        else if(y_axis > 2)
            y_axis = 2;
        else if(x_axis < 0)
            x_axis = 0;
        else if(y_axis < 0)
            y_axis = 0;

        if(maze_for_check[x_axis][y_axis] != 'O' || maze_for_check[x_axis][y_axis] != 'X')
        { 
            tic_tac_set_maze_values(maze_for_check, x_axis, y_axis, 'O');
        }
    }
}

int tic_tac_getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}


int tic_tac_arrow_key()
{
    char user_in;

    user_in = tic_tac_getch();

    if (user_in == '\033') 
    { // if the first value is esc
        tic_tac_getch(); // skip the [
        switch(tic_tac_getch()) 
        { // the real value
            case 'A':
                return TIC_UP; // code for arrow up
                break;
            case 'B':
                return TIC_DOWN; // code for arrow down
                break;
            case 'C':
                return TIC_RIGHT; // code for arrow right
                break;
            case 'D':
                return TIC_LEFT; // code for arrow left
                break;
            /*add default*/
        }
    }
    else if(user_in == '\n')
    {
        return TIC_ENTER;
    }

    return TIC_INVALID;
}

void tic_tac_print_menu()
{
    printf("*****************************************************\n");
    printf("*********** Welcome to Tic Tac Toe ******************\n");
    printf("*****************************************************\n");

    printf("Start Game:\t\t1\n"); 
    printf("Help:      \t\t?\n");
    printf("\n");
}

char **tic_tac_create_maze()
{
    int i,j;
    char **tmp; 
    
    tmp = (char **)calloc(ROWS_MAX, sizeof(char *));
    if(tmp == NULL)
    {
        perror("Malloc Failed!");
        printf("errno = %d.\n", errno);
        exit(1);
    }

    for(i=0;i<COLS_MAX;i++)
    {
        tmp[i] = (char *)calloc(COLS_MAX , sizeof(char));  
        if(tmp[i] == NULL)
        {
            perror("Malloc Failed!");
            printf("errno = %d.\n", errno);
            exit(1);   
        }
    }

    for(i=0;i<COLS_MAX;i++)
    {
        for(j=0;j<ROWS_MAX;j++)
        {
            tmp[i][j] = '-';
        } 
    }
    return tmp;
} 

void tic_tac_destroy_maze(char** maze)
{
    int i;

    for(i=0;i<COLS_MAX;i++)
    {
        if(maze[i] != NULL)
        {
            free(maze[i]);
            maze[i] = NULL;
        }
    }
    if(maze != NULL)
    {
        free(maze);
        maze = NULL;
    }
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


int tic_tac_set_maze_values (char **maze, int x, int y, char value)
{
    if(value == 'X' || value == 'O' || value == '-' ) 
    {
        if(maze[x][y] == '-' || value == '-')
        {
            maze[x][y] = value;
        }
    }
    else
    {
        printf("Only X and O's allowed");
        return N_ERROR;
    }
}


//Return value from each function and write doxygen comments about each function
//Create a header file with all the definiations and another header file with all the function prototypes. 
//Create a new thread that keeps looking at the game combination and use mutex to sychronize data. 
//Create a library for the tictactoe.so and link it to the application






















