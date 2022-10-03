#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node*next;
};

void linkedlistTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* insertionAtFirst(struct Node*head, int data){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node* insertAtIndex(struct Node*head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;
    while (i != index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct Node* insertAtEnd( struct Node *head, int data ){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;
    while (p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct Node * insertAfterNode(struct Node* head, struct Node* prevNode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}


int main (){
    // creating nodes in the linked list
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    
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
    
    // printing elements with the function without insertion
    linkedlistTraversal(head);
    // printing elements with the function after inserting at the beginning
    // head = insertionAtFirst(head, 56);
    // printing elements with the function after inserting at the index
    // head = insertAtIndex(head, 10, 1);
    // printing elements with the function after inserting at the end
    // head = insertAtEnd(head, 100);
    // printing elements with the function after inserting at the end
    insertAfterNode(head, third, 1000);
    printf("\n");
    linkedlistTraversal(head);



    return 0;
}