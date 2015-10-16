#include <stdio.h>

void printfunc(char *ptr);

int main(int argc, char argv[])
{
    static unsigned char array[5] = {0x00, 0x01, 0x02, 0x03, 0x04};
    
    printfunc(&array[1]); 
        
    return 0;
}


void printfunc(char *ptr)
{
    printf("Value is 0x%02x \n", ptr[0]);
    printf("Value is 0x%02x \n", ptr[1]);
    printf("Value is 0x%02x \n", ptr[2]);
}
