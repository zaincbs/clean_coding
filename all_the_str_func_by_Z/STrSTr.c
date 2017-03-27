#include<stdio.h>


const char *mystrstr(const char* str, const char* substr)
{

    while( *str )
    {
        const char *beg_str = str;
        const char *sub_tmp = substr;

        while( *str && *sub_tmp && *str == *sub_tmp )
        {
            str++;
            sub_tmp++;
        } 
        if(!*sub_tmp++)
            return beg_str;

        str = beg_str + 1;

    }

}

int main()
{
    char tmp1[20] = "My Zai is Zain ni";
    char tmp2[20] = "Zain";

    printf("\n%s\n", mystrstr(tmp1, tmp2) );

}
