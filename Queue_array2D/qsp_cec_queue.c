/**                                                                                                                                   
 * @file        qsp_cec_queue.c
 * @brief       Use QSP Manual Lookup APIs to find a codeset.
 *
 */

/*
 * COPYRIGHT 2015 UNIVERSAL ELECTRONICS INC (UEI).
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

#include <stdio.h>
#include <string.h>

/*
 ********************************************************************************
 * Constants.
 ********************************************************************************
 */

/*
 ********************************************************************************
 * Data Types.
 ********************************************************************************
 */

/*
 ********************************************************************************
 * Prototypes.
 ********************************************************************************
 */

/*
 ********************************************************************************
 * Globals.
 ********************************************************************************
 */
int  cec_rx_cirQ[10][32];


void display (int cirQ[], int Front, int Rear, int size)
{
    int i;
    printf (“\n The contents of queue are:”);
    i=Front;
    while ( i != Rear)
    {
        i = (i + 1) % size;
        printf (“%d ”, cirQ[i]);
    }
}


int addQ (int cirQ[],int * Front, int *Rear, int val[], int size)
{
    if ( ((*Rear + 1) % size) == *Front)
        return 0;/* the queue is Full */
    else
    {
        *Rear= (*Rear + 1) % size;
        cirQ[*Rear]= val;
        return 1;
    }
}

int main()
{
    int Front;
    int Rear;
    int val;
    int size;
    int result;


    Front = Rear = 0;
    
    
}




