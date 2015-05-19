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
void create_maze(char*** maze);
void print_maze(char** func_maze);
void destroy_maze(char** maze);


int main( int argc, char *argv[] )
{
    char **maze_ptr = NULL;

    create_maze(&maze_ptr);

    print_maze(maze_ptr);

    destroy_maze(maze_ptr);

    return 0;
}


void create_maze(char*** maze)
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

void destroy_maze(char** maze)
{
    int i;

    for(i=0;i<COLS_MAX;i++)
    {
            free(maze[i]);
    }

    free(maze);
}

void print_maze(char **func_maze)
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
}






























