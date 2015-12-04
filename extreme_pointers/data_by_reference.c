#include<stdio.h>
#include<stdlib.h>
typedef struct co_ordinates_t
{
    int x;
    int y;
}co_t;

#if 0
void increment_co_t(co_t ptr)
{
   (ptr.x)++;
   (ptr.y)++; 
}

int main()
{
    co_t my_cordinates;

    my_cordinates.x = 0;
    my_cordinates.y = 0;

    increment_co_t(my_cordinates);


    return 0;
}
#elseif 1
void increment_co_t(co_t *ptr)
{
   (ptr->x)++;
   (ptr->y)++; 
}

int main()
{
    co_t my_cordinates;

    my_cordinates.x = 0;
    my_cordinates.y = 0;

    increment_co_t(&my_cordinates);


    return 0;
}
#endif


#if 1
void increment_co_t(co_t *ptr)
{
   (ptr->x)++;
   (ptr->y)++; 
}

int main()
{
    co_t *my_cordinates = (co_t *)malloc(sizeof(co_t *));

    my_cordinates->x = 0;
    my_cordinates->y = 0;

    increment_co_t(my_cordinates);

    return 0;
}
#endif
