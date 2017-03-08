#include<stdio.h>

char *STRSTR( const char *haystack, const char *needle );

int main()
{
    const char main_str[ 20 ] = "My Name is Zain";
    const char lookup_string[ 20 ] = "is Zain";

    printf( "%s", STRSTR( main_str, lookup_string ) );
}


char *STRSTR( const char *haystack, const char *needle )
{
    while( *haystack )
    {
        const char *str_start = haystack;
        const char *sub_str = needle;

        while( *haystack && *sub_str && *haystack == *sub_str )
        {
            haystack++;
            sub_str++;
        }
        if(!*sub_str)
            return (char *)str_start;

        haystack = str_start + 1;
    }
    return NULL;
}
