#include <stdio.h>

void func1(int array[], int length){
    int sum=0;
    int product=1;
    for (int i=0; i<length; i++){
        sum+=array[i];
    }
    for (int j=0; j<length; j++){
        product*=array[j];
    }
    // printf("%d\n", sum);
    // printf("%d\n", product);
}

int main(){
    int arr[] = {3,5,29};
    // int length = 3
    func1(arr, 3);
    return 0;
}