typedef int (*nb_send_host_log_func_t )( int severity );

int nb_set_log_level_func( nb_send_host_log_func_t fn);
