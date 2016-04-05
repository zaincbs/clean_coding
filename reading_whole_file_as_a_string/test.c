#include<stdio.h>
#include <stdlib.h>


int main()
{
    FILE *ptr;
    int length;
    char *buffer;
    ptr = fopen("avr_data.ip", "r");
    
    if (ptr!=NULL)
    {
        fseek (ptr, 0, SEEK_END);
        length = ftell (ptr);
        fseek (ptr, 0, SEEK_SET);
        buffer = malloc (length);
        if (buffer)
        {
            fread (buffer, 1, length, ptr);
        }   
        fclose(ptr);
    }

    printf("%s", buffer);

    free(buffer);
    
}
