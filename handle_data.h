#define ASCII_LETTER_A 65
#define NUM_OF_LETTERS 26

static const int HIGH = 100000;
static const int LOW = 10000;

void createDataFile(const char * dataFileName);

void readDataFile(const char* dataFileName);

int generateLetter();

int generateNumber();

int getNumberOfLinesInFile(const char* inputFile);


struct SEntity{
    char id[3];
    char state[3];
    int number;
};

void printSEntity(struct SEntity input);
