#include <stdio.h>

void display(int arr[], int size){
    for (int i =0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insert(int arr[], int size, int element, int cap, int index){
    if(size>=cap){
        printf("%d ", "Could Not Insert");
    }
    for(int i = size-1; i>=index; i--){
        arr[i+1] = arr[i];
    }
    size++;
    arr[index] = element;
    display(arr, size);
    return 0;
}

int main(){
    int index = 99, element = 99, cap = 100;
    int arr[100] = {1, 2, 27, 100, 8};
    display(arr, 100);
    insert(arr, 5, element, cap, index);
    return 0;
}