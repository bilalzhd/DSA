#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};


int max(int a, int b){
    return a ? a > b : b;
}

int getHeight(struct Node* n){
    if(n == NULL) return 0;
    return n->height;
}

struct Node* createNode(int data){
    struct Node* node = (struct Node*) malloc (sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int balanceFactor (struct Node* n){
    if(n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

struct Node* leftRotate(struct Node* x){
    struct Node* y = x->right;
    struct Node* t = y->left;

    y->left = x;
    x->right = t;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return y;
}

struct Node* rightRotate(struct Node* y){
    struct Node* x = y->left;
    struct Node* t = x->right;

    x->right = y;
    y->left = t;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return x;
}

void preOrderTraversal(struct Node* node){
    if(node != NULL){
        printf("%d", node->data);
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

struct Node* insert(struct Node* node, int data){
    if(node == NULL) return createNode(data);

    if(node->data < data) node->left = insert(node->left, data);
    else if(node->data > data) node->right = insert(node->right, data);
    int bf = balanceFactor(node);
    if(bf > 1 && data < node->left->data){
        return rightRotate(node);
    }
    if(bf < -1 && data > node->right->data){
        return leftRotate(node);
    }
    if(bf > 1 && data > node->left->data){
        node->left = leftRotate(node);
        return rightRotate(node);
    }
    if(bf < -1 && data < node->right->data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;

}

int main(){
    struct Node* root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrderTraversal(root);
    return 0;
}

