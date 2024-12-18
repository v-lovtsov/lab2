#ifndef validations_h
#define validations_h

#include <string.h>

// Validate input
int validate(char * P) {
    int size = strlen(P);

    // Size check
    if (size > 10 || size < 1)
        return 0;
    
    // Validate string (it has to be num)
    for (int i = 0; i < size; i++)
        if ((int)P[i] < (int)'0' || (int)P[i] > (int)'9')
            return 0;
    
    // Check for permutation possibility
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (P[i] == P[j])
                return 0;

    return 1;
}

#endif