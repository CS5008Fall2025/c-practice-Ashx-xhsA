#include <stdio.h> // basic input and output
#include <stdlib.h> // standard library

int BUFF_SIZE = 50;

int main(int argc, char** argv ){
    // char buff[BUFF_SIZE]; 

    FILE *input = fopen(argv[1],"r");
    char* line = malloc(BUFF_SIZE * sizeof(char));
    int counter = 0;
    while (fgets(line, BUFF_SIZE, input) != NULL) {
    // do the thing, line now has the line from input
        printf("%d\n",counter);
        printf("%s \n", line);
        counter++;
}

    free(line); // don't forget to free memory!
    fclose(input); // don't forget to close a file!

    return 0;
}