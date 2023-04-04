#include <stdio.h>

void printArray(int* A, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", A[i]);
    }
}

void bubbleSort(int *A, int size){
    int temp;
    for (int i = 0; i < size - 1; i++){             // for number of passes
    printf("Working on pass number: %d\n", i);
        for (int j = 0; j < size-1-i; j++){         // for number of comparisons
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int *A, int size){
    int temp;
    int isSorted = 0;
    for (int i = 0; i < size - 1; i++){
    printf("Working on pass number: %d\n", i);
    isSorted = 1;
        for (int j = 0; j < size-1-i; j++){
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
}

int main(){
    int A[] = {7, 3, 1, 2, 4};
    int n = 5;
    printArray(A, n);
    printf("\n");
    bubbleSortAdaptive(A, n);
    printArray(A, n);
    return 0;
}
