#include<stdio.h>
#include"nb_logger.h"

int log_test(int severity, const char* msg)
{
    printf("Severity %d, msg=%s\n", severity, msg);
    return 0;
}

int main()
{
    nb_set_log_level_func(log_test);
    return 0;
}
