#include<stdio.h>



char *STRSTR( char *str, char *ned );

int main()
{

    char hay[20] = "My namn name is Zain";
    char ned[20] = "name";

    printf( "%s\n", STRSTR(hay,ned) );
}

char *STRSTR( char *str, char *ned )
{
    /*Triverse through the whole main string.*/
    while( *str )
    {
        char *Begin = str;
        char *substr = ned;

        while( *str && *substr && *substr == *str )
        {
            str++;
            substr++;
        }

        if(!*str)
            return Begin;
        
        str = Begin + 1; /*go to the next character in the main string*/
    }
}
