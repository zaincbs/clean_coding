#include <stdio.h>
#include <stdlib.h>

/*Data Structure of Linklist*/
typedef struct node_data_t
{
    int data;
    struct node_data_t      *next_highest;
    int h_data;
    struct node_data_t *nxt_ptr;
}node_t;
