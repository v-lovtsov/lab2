#ifndef utils_h
#define utils_h

#include <stdlib.h>
#include <string.h>

// Generate and fill empty new string
char * generateString(int size) {
    char * str = (char *)malloc(size * sizeof(char));
    for (int i = 0; i < size; i++)
        str[i] = '\0';

    return str;
}

// Get equal digit from char symbol
int numfrmch(char num) {
    if ((int)num <= (int)'9')
        return (int)num - '0';

    if ((int)num <= (int)'Z')
        return (int)num - 'A' + 10;

    if ((int)num <= (int)'z')
        return (int)num - 'a' + 10;

    return 0;
}

// Get equal digit array from string
int * intArrFromStr(char * P) {
    int size = strlen(P);
    int * arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        arr[i] = numfrmch(P[i]);

    return arr;
}

// Swap two elements from array
void swap(int * n1, int * n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

// Bubble sort
void sort(int * P, int start, int end) {
    for (int i = start; i < end; i++)
        for (int j = i + 1; j < end; j++)
            if (P[j] < P[i])
                swap(&P[i], &P[j]);
}

// Print array of integer nums
void printArray(int * P, int size) {
    for (int i = 0; i < size; i++)
        printf("%d", P[i]);
    
    printf("\n");
}


// Create new array and copy to it other
int * copyArray(int * arr, int size) {
    int * new_arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        new_arr[i] = arr[i];
        
    return new_arr;
}

#endif