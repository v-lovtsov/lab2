#ifndef permutations_h
#define permutations_h

#include "utils.h"
#include <string.h>

#define uint unsigned int

// Generates next permutations by Narayana's algorithm
uint * generateNextPermutation(uint * P, uint size) {
    uint * copy = copyArray(P, size);

    // First number to swap
    int maxi = -1;
    // Second number to swap
    int maxl = -1;

    // Search for maxi
    for (int i = size - 2; i >= 0; i--) {
        uint num_next = copy[i + 1];
        uint num_prev = copy[i];
        
        if (num_prev < num_next) {
            maxi = i;
            break;
        }
    }

    
    if (maxi == -1) {
        free(copy);
        return NULL;
    }

    // Search for maxla
    for (int l = size; l > maxi; l--) {
        uint num = copy[l];
        
        if (num > copy[maxi]) {
            maxl = l;
            break;
        }
    }

    swap(&copy[maxi], &copy[maxl]);

    sort(copy, (uint)maxi + 1, size);

    return copy;
}

#endif