#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    int * arr;
};

int isEmpty (struct Stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
};
int isFull (struct Stack * ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    return 0;
};

void push (struct Stack * ptr, int element){
    if(isFull(ptr)){
        printf("The Stack is full");
    }
    ptr->top++;
    ptr->arr[ptr->top] = element;
};

int pop(struct Stack * ptr){
    if(isEmpty(ptr)){
        printf("The Stack is already Empty");
        return -1;
    }
    int top = ptr->arr[ptr->top];
    ptr->top--;
    return top;
}

int peek(struct Stack * ptr, int i){
    int arrayInd = ptr->top - i + 1;
    if(arrayInd< 0){
        printf("Invalid Position");
        return -1;
    }
    return ptr->arr[arrayInd];
}

int main(){
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *) malloc (s->size * sizeof(int));

    printf("%d\n", isEmpty(s));
    printf("%d\n", isFull(s));
    printf("\n");

    push(s, 10);
    push(s, 10);
    push(s, 10);
    push(s, 10);
    push(s, 10);
    push(s, 10);
    push(s, 10);
    push(s, 10);
    push(s, 10);
    push(s, 190); // Full
    printf("%d\n",pop(s));
    printf("%d\n", isEmpty(s));
    printf("%d\n", isFull(s));
    
    // Peeking
    for (int j = 0; j < s->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(s, j));
    }
    
    
    return 0;
}