#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    };
};

// Case 1:
struct Node* deleteFromStart(struct Node* head){
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
};

// Case 2:
struct Node * deleteAtEnd(struct Node* head){
    struct Node* p = head;
    struct Node * q = head-> next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// Case 3:
struct Node * deleteAtIndex(struct Node* head, int index){
    struct Node* p = head;
    struct Node * q = head-> next;
    for(int i =0; i < index-1; i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// Case 4:
struct Node* deleteAtGivenValue(struct Node * head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    
    while(q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}

int main (){
    // creating nodes in the linked list
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    
    // creating memory in heap dynamically
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    
    // assigning values to the nodes
    head->data = 7;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 12;
    third->next = fourth;
    fourth->data = 48;
    fourth->next = NULL;
    
    linkedlistTraversal(head);
    printf("\n");
    // head = deleteFromStart(head);
    // head = deleteAtEnd(head);
    // head = deleteAtGivenValue(head, 11);
    // head = deleteAtIndex(head, 7);
    linkedlistTraversal(head);


    return 0;
}
/*

struct Node * insertAtEnd(struct Node * head){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    ptr->data = 7;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
} 

*/