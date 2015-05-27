/**
 *
 * @file        tic_tac_toe.h
 *
 * @brief       Tic tac toe header file 
 *
 * @Author      Zain Ijaz
 *
 * @Occupation  Software Engineer
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

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#ifdef __cplusplus
extern "C" {
#endif

void tic_tac_print_menu();
char **tic_tac_create_maze();
void tic_tac_print_maze(char** func_maze);
void tic_tac_destroy_maze(char** maze);
void tic_tac_set_maze_values (char **maze, int x, int y, char value); 
void tic_tac_arrow_key();
int  tic_tac_getch(void);


#ifdef __cplusplus
}
#endif

#endif /*TIC_TAC_TOE_H*/


