#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;

struct Node{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int dequeue(){
    int val = -1;
    struct Node* ptr = f;
    if(f==NULL){
        printf("The queue is empty");
        return -2;
    } else {
        f = f->next;
        val = ptr->data;
        return val;
        free(ptr);
    }
}

void enqueue(int val){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL){
        printf("Queue is full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if (f == NULL){
            f = r = n;
        }
        else{
            r->next = n;
            r = n;
        }
    }
}

int main(){
    linkedlistTraversal(f);
    enqueue(30);
    enqueue(17);
    printf("Dequeing element is %d\n", dequeue());
    linkedlistTraversal(f);
}