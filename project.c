#include <stdio.h>
#include <string.h> // for strcmp()
#include <stdlib.h> // 'for exit();
#include "handle_data.h"


int main(int argc, char * argv[])
{
    if (argc != 3)
    {
        puts("Not enough arguments...");
        puts("Program syntax options:");
        puts("1) program_name c file_name");
        printf("2) program_name r file_name\n");
        exit(1);

    }

    if ( !strcmp(argv[1], "c") )
    {
        createDataFile(argv[2]);

    }
    else if ( !strcmp(argv[1], "r") )
    {
        readDataFile(argv[2]);

    }

    return 0;

}
