// Breadth First Search implementation in a graph;

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

    // BFS Implementation
    int i = 0;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0}
    };

    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i);
    while(!isEmpty(&q)){
        int node = dequeue(&q);
        for(int j=0; j<7; j++){
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    return 0;
}