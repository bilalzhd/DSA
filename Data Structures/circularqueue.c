#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct CircularQueue* ptr){
    if((ptr->r+1) % ptr->size == ptr->f){
        return 1; 
    }
    return 0;
}
int isEmpty(struct CircularQueue* ptr){
    if(ptr->r == ptr->f){
        return 1;
    }
    return 0;
}

void enqueue(struct CircularQueue* ptr, int val) {
    if(!isFull(ptr)){
        ptr->r = (ptr->r + 1 % ptr->size);
        ptr->arr[ptr->r] = val;
    } else {
        printf("This Queue is Full");
    }
}

int dequeue(struct CircularQueue* ptr){
    if(!isEmpty(ptr)){
        ptr->f = (ptr->f + 1) % ptr->size;
        int first = ptr->arr[ptr->f];
        return first;
    } else {
        printf("The queue is empty");
        return -1;
    }
}

int main () {
    struct CircularQueue q;
    q.size = 100;
    q.f = q.r = 0;
    q.arr = (int *) malloc (q.size * sizeof(int));

    enqueue(&q, 10);
    enqueue(&q, 15);
    if(isEmpty(&q)){
        printf("Queue is empty");
    } else {
        printf("Queue is not empty");
    }
    printf("\n");
    int dequed = dequeue(&q);
    int dequed2 = dequeue(&q);
    printf("Dequeuing element is %d %d",dequed, dequed2);

    return 0;
}