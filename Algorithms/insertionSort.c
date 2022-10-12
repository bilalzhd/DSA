#include <stdio.h>

void print(int* A, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    
}
void insertionSort(int* arr, int n){
    for (int i=1; i <= n-1; i++){
        int key, j;
        key = arr[i];
        j = i - 1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
}

int main(){
    int arr[] = {56, 1, 2, 18, 10, 15};
    int size = 6;
    print(arr, size);
    insertionSort(arr, size);
    print(arr, size);
    return 0;
}