#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int f;
    int r;
    int* arr;
};
int isFull(struct Queue* ptr){
    if(ptr->r == ptr->size-1){
        return 1;
    }
    return 0;
}
int isEmpty(struct Queue* ptr){
    if(ptr->r == ptr->f){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue* ptr, int val) {
    if(!isFull(ptr)){
        ptr->r++;
        ptr->arr[ptr->r] = val;
    } else {
        printf("This Queue is Full");
    }
}

int dequeue(struct Queue* ptr){
    if(!isEmpty(ptr)){
        ptr->f++;
        int first = ptr->arr[ptr->f];
        return first;
    } else {
        printf("The queue is empty");
        return -1;
    }
}

int main () {
    struct Queue q;
    q.size = 100;
    q.f = q.r = -1;
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