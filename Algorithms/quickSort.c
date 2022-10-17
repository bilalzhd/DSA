#include <stdio.h>

void printArray(int* arr, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int temp;
    int i = low + 1;
    int j = high;

    do {
        while (arr[i] <= pivot){
            i++;
        }
        while (arr[j] > pivot){
            j--;
        }
        if (i < j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    // Swap arr[low] and arr[j]
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int arr[], int low, int high){
    int partitionIndex;
    if (low < high){
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main(){
    int arr[] = {18, 2, 13, 6, 0, 11};
    int n = 6;
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    printf("\n");
    printArray(arr, n);
    return 0;
}