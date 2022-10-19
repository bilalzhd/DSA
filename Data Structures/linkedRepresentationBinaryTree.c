#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* n;
    n = (struct Node*) malloc (sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}

int main(){
    struct Node* root = createNode(2);
    struct Node* child1 = createNode(1);
    struct Node* child2 = createNode(4);
     
    return 0;
}