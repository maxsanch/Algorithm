#include <stdio.h>
#include <stdlib.h>

long int* new_array(long int n) {
    long int* new_array = malloc(n*sizeof(long int));

    for(int i=0; i<n; i++) {
        new_array[i] = i;
    }

    return new_array; 
}

long int direct_access (long int* array, long int index) {
    return array[index];
}

void print_array(long int* array, long int n) {
    printf("( ");

    for(long int i = 0; i<n; i++) {
        printf("%ld ", array[i]);
    }

    printf(") \n");
}

long int* insertionArray (long int* array, long int n, long int i, long int value) {
    long int* insertedArray = malloc((n+1) * sizeof(long int));

    for(long int j = 0; j<i; j++) {
        insertedArray[j] = array[j];
    }

    insertedArray[i] = value;

    for(long int j = i+1; j<=n; j++) {
        insertedArray[j] = array[j];
    }

    return insertedArray;
}

long int* deletionArray(long int* array, long int n, long int i) {
    long int* DeletionArray = malloc((n - 1) * sizeof(long int));

    for(long int j = 0; j<i; j++) {
        DeletionArray[j] = array[j];
    }

    for(long int j = i; j<=n-1; j++) {
        DeletionArray[j] = array[j+1];
    }

    return DeletionArray;
}

void main() {
  long int* array = new_array(10);
  print_array(array, 10);

  print_array(deletionArray(array, 10, 4), 9);
}