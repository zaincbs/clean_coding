#include <stdlib.h>
#include <stdio.h>



int **init_alloc();
void zeroit(int **array, int nrows, int ncolumns);
void printit(int **array, int nrows, int ncolumns);


int nrows = 3;
int ncolumns = 3;

int main()
{
    
    int **array;
    array = init_alloc(&array);

    printit(array, nrows, ncolumns);

    zeroit(array, nrows, ncolumns);

    printit(array, nrows, ncolumns);

}



int  **init_alloc()
{
    int i;
    int **array;

    array = malloc(nrows * sizeof(int *));
    if(array == NULL)
    {
        printf("out of memory\n");
    }
    for(i = 0; i < nrows; i++)
    {
        array[i] = malloc(ncolumns * sizeof(int));
        if(array[i] == NULL)
        {
            printf("out of memory\n");
        }
    }
    return array;
}


void zeroit(int **array, int nrows, int ncolumns)
{
    int i, j;
    for(i = 0; i < nrows; i++)
    {
        for(j = 0; j < ncolumns; j++)
            array[i][j] = 1;
    }
}

void printit(int **array, int nrows, int ncolumns)
{
    int i, j;
    for(i = 0; i < nrows; i++)
    {
        for(j = 0; j < ncolumns; j++)
            printf("%d\n", array[i][j]);
    }
}
