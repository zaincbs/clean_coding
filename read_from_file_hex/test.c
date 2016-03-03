#include<stdio.h>
#include <stdlib.h>

#define MAX_CEC_STRING_LENGTH 100
#define CEC_FILE_NAME "samsung_avr_cec.txt"

int main()
{

    int                     vendor_id = 0x00;
    int                     logic_address = 0x00; 
    char                    osd[MAX_CEC_STRING_LENGTH];    
    char                    phy_add[MAX_CEC_STRING_LENGTH];
    FILE *                  cec_file;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;


    cec_file = fopen( CEC_FILE_NAME, "r" );

    read = getline(&line, &len, cec_file);
    {
        sscanf(line, "0x%02x", &logic_address);
        printf("0x%02x\n", logic_address);
    }
    read = getline(&line, &len, cec_file);
    {
        sscanf(line, "0x%02x", &vendor_id);
        printf("0x%02x\n", vendor_id);
    }
    read = getline(&line, &len, cec_file);
    {
        sscanf(line, "%s", osd);
        printf("%s\n", osd);
    }
    read = getline(&line, &len, cec_file);
    {
        sscanf(line, "%s", phy_add);
        printf("%s\n", phy_add);
    }
   
    fclose(cec_file);

    if (line)
        free(line);

}
