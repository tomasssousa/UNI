#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int processcounter = 1;
    
    for (int i = 0; i < 4; i++) {
        fork();
        processcounter = processcounter * 2;
    }

    printf("O número total de processos é igual a: %d\n", processcounter);

    exit(EXIT_SUCCESS);
}