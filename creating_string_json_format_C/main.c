#include<stdio.h>
#include <string.h>



#define MAX_KEY_JSON_STRING_LEN 255


const char * h_create_j_string_for_keys( int key_num, char *key_state, char *remote_type, char * remote_id );

int main()
{

    int key_num = 12;
    char *key_state = "Down";
    char *remote_type = "type_num";
    char *remote_id = "id_num";
    char j_string[MAX_KEY_JSON_STRING_LEN] = {0};

    strcpy(j_string, h_create_j_string_for_keys(key_num, key_state, remote_type, remote_id));

}

const char * h_create_j_string_for_keys( int key_num, char *key_state, char *remote_type, char * remote_id )
{
    
    static char r_string[MAX_KEY_JSON_STRING_LEN] = {0};

    sprintf(r_string, "{\"userInput\":%d, \"keyState\":\"%s\", \"remoteType\":\"%s\",\"remoteId\":\"%s\"}", key_num, key_state, remote_type, remote_id );

    printf("Value is: %s\n", r_string);

}
