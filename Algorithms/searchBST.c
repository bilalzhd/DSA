// PreOrder, PostOrder and Inorder Traversal in a Binary Tree

#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* searchRecursive(struct Node* root, int key){
    if(root == NULL) return NULL;
    else if(root->data == key) return root;
    else if(key < root->data){
        searchRecursive(root->left, key);
    } else {
        return searchRecursive(root->right, key);
    }
}

struct Node* searchIterative(struct Node* root, int key){
    while(root != NULL){
        if(key == root->data) return root;
        else if(root->data > key) root = root->left;
        else root = root->right;
    }
    return NULL;
}
struct Node* createNode(int data){
    struct Node* n;
    n = (struct Node*) malloc (sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}


int main(){
    struct Node* p = createNode(10);
    struct Node* p1 = createNode(8);
    struct Node* p2 = createNode(11);
    struct Node* p3 = createNode(7);
    struct Node* p4 = createNode(9);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // struct Node* n = searchRecursive(p, 110);
    struct Node* n = searchIterative(p, 10);

    if(n != NULL){
        printf("Element found: %d", n->data);
    } else {
        printf("element not found");
    }
    return 0;
}