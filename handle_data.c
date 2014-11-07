#include <stdio.h> // for  sprintf;
#include <stdlib.h> // for rand();
#include <time.h>

#include "handle_data.h"

const int file_size[4] = {5, 10, 15, 20};

void createDataFile(const char * dataFileName)
{
    FILE* fPointer = fopen(dataFileName, "w");
    if (fPointer == NULL)
    {
        printf("Error creating the file: %s\n", dataFileName);
    }

    // initialize random seed
    srand (time(NULL));

    // randomly determine the number of lines to generate in the file
    int num_lines_to_generate = file_size[rand() % 4];

    int i = 0;
    char  *currentLine = (char *) malloc(20 * sizeof(char));

    for(; i < num_lines_to_generate; i++)
    {
        sprintf(currentLine, "%02i, %c%c, %i", i, generateLetter(), generateLetter(), generateNumber()); // sprintf add the null char at the end
        fprintf(fPointer, "%s\n", currentLine);
        //puts(currentLine);
    }
    
    free(currentLine);
    fclose(fPointer);
}


void readDataFile(const char* dataFileName)
{
    FILE* fPointer = fopen(dataFileName, "r");
    if (fPointer == NULL)
    {
        printf("Error reading  the file: %s\n", dataFileName);
    }

    int line_count = -1;
    line_count = getNumberOfLinesInFile(dataFileName);

    struct SEntity* pListEntity;
    int index = 0;
    
    if (line_count > 0)
    {
        // Pointer to an array of struct SEntities
        pListEntity = (struct SEntity *) malloc( sizeof(struct SEntity) * line_count );

        //puts("Here is the data in the the file");
        char singleLine[150] = {0};
        while( !feof(fPointer) )
        {
            fgets(singleLine, 150, fPointer); // fgets adds '\0' add the end
            sscanf(singleLine, "%2s, %2s, %i\n", pListEntity[index].id, pListEntity[index].state, &(pListEntity[index].number));
            printSEntity(pListEntity[index]);
            //printf("%s", singleLine);
        }
    }
    fclose(fPointer);
    free(pListEntity);
}


int generateLetter()
{
    
    return (rand() % NUM_OF_LETTERS) + ASCII_LETTER_A;
}


int generateNumber()
{
    return (rand() % (HIGH - LOW)) + LOW;
}


int getNumberOfLinesInFile(const char* inputFile)
{
    FILE* fPointer = fopen(inputFile, "r");
    int ch, line_count = 0;

    do 
    {
        ch = fgetc(fPointer);
        if(ch == '\n')
        	line_count++;
    } while (ch != EOF);

    // This accounts for the case in which there is only one line in the file
    // and for the last line in the file which will not have a new line character
    if(ch != '\n' && line_count == 0) 
        line_count++;

    fclose(fPointer);

    printf("number of lines in %s is %i\n", inputFile, line_count);
    return line_count;

}

void printSEntity(struct SEntity input)
{
    printf("id = %s, ", input.id);
    printf("state = %s, ", input.state);
    printf("number = %i\n", input.number);
}
