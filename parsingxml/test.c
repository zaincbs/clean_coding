#include<stdio.h>
#include <string.h>



int main()
{
    char *xml = NULL;
    char *port_switch = NULL;
    const char del_port[] = " ,;:!-=\"";

    xml = strdup("<key active_src=\"2.3.0.0\" />");

    port_switch = strstr( (char *)xml, "key active_src=" );
    if( port_switch )
    {
        printf("%s\n", port_switch);
        port_switch+=strlen("key active_src=\"");
        printf("Received command for Switching the Port to : %c\n", port_switch[0]);
/*
        port_switch = strstr( (char *)xml, "source=" );
        port_switch = strtok( status, del_port );
        printf("%s\n", port_switch);
        port_switch = strtok( NULL, del_port );
        printf("%s\n", port_switch);
*/
    }

    



}
