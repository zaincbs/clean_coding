#include<stdio.h>
#include"nb_logger.h"


int nb_set_log_level_func( nb_send_host_log_func_t fn)
{
    fn(20,"Zain");    
    return 0;
}

