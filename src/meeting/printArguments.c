#include <stdio.h> // basic input and output
#include <stdlib.h> // standard library

int main(int argc, char** argv ){
    for(int i= 0;i< argc;i ++){
        printf("\n %d : %s", i, argv[i]);
    }
    return 0;
}