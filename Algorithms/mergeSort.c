#include <stdio.h>

void printArray(int* A, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", A[i]);
    }
}

void merge(int A[], int low, int mid, int high){
    int i,j,k, B[100];
    i = low;
    j = mid+1;
    k = low;

    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            B[k] = A[i];
            i++; k++;
        } else {
            B[k] = A[j];
            j++; k++;
        }
    }
    while(i <= mid){
        B[k] = A[i];
        k++; i++;
    } 
    while (j <= high){
        B[k] = A[j];
        k++; j++;
    }
    for (int i = low; i <= high; i++){
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high){
    int mid = (low + high) / 2;
    if(low < high){
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}


int main(){
    int A[] = {1, 0, 12, 2, 3, 3, 18};
    int n = 7;
    printArray(A, n);
    mergeSort(A, 0, n-1);
    printf("\n");
    printArray(A, n);
    return 0;
}