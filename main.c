#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "utils.h"
#include "permutations.h"
#include "validations.h"

#define STRING_SIZE 100

#define uint unsigned int

int main() {
    char * P = generateString(STRING_SIZE);
    uint n;

    if (!P)
        return 1;

    if (!fgets(P, STRING_SIZE, stdin)) {
        free(P);
        return 0;
    }
    if (!scanf("%u", &n)) {
        free(P);
        return 0;
    }

    P[strlen(P) - 1] = '\0';
    

    if (!validate(P)) {
        printf("bad input");
        free(P);
        return 0;
    }

    uint * currentPermutation = intArrFromStr(P);
    for (uint i = 0; i < n; i++) {
        uint * newPermutation = generateNextPermutation(currentPermutation, strlen(P));
        free(currentPermutation);
        currentPermutation = newPermutation;
        if (currentPermutation == NULL)
            break;

        printArray(currentPermutation, strlen(P));
    }


    free(P);
    free(currentPermutation);

    return 0;
}