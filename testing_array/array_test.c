#include<stdio.h>
 #include <string.h>

#define MAX_NUMBER_OF_PORTS 12
#define MAX_PORT_STRING_LENGTH 12*4

int main()
{
    int port_array[MAX_NUMBER_OF_PORTS] = {1,1,0,0};
    int port_array_sz = 4;

    char port_string[MAX_PORT_STRING_LENGTH];

    int i,j = 0; 


    for(i=0;i<port_array_sz;i++)
    {    
        sprintf(&port_string[j], "%d", port_array[i]);
        if(i < port_array_sz-1)
        {
            sprintf(&port_string[++j], "%c", ',');
            j++;
        }

        memset(port_array, port_array_sz, 0x00);
    }    


    printf("Here it is %s\n", port_string);
}
