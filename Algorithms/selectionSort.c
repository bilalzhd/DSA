#include <stdio.h>

void print(int* A, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int* A, int n){
    int indexOfMin, temp;
    for (int i = 0; i < n-1; i++){
        indexOfMin = i;
        for (int j=i+1; j<n; j++){
            if(A[j] < A[indexOfMin]){
                indexOfMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main(){
    int A[] = {44, 1, 180, 27, 22220, 5};
    int size = 6;
    print(A, size);
    selectionSort(A, size);
    print(A, size);
    return 0;
}