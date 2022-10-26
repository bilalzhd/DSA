#include <stdio.h>
#include <malloc.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

int max(int a, int b){
    return a > b ? a : b;
}

int getHeight(struct Node* n){
    if(n == NULL) return 0;
    return n->height;
}

struct Node* createNode(int key){
    struct Node* node = (struct Node *) malloc (sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int getBalanceFactor(struct Node * n){
    if(n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

struct Node* leftRotate(struct Node* x){
    struct Node * y = x->right;
    struct Node * t = y->left;

    y->left = x;
    x->right = t;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;

}

struct Node* rightRotate(struct Node* y){
    struct Node * x = y->left;
    struct Node * t = x->right;

    x->right = y;
    y->left = t;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;

}

struct Node * insert(struct Node* n, int key){
    if(n == NULL) return createNode(key);
    if(key < n->key){
        n->left = insert(n->left, key);
    }
    else if(key > n->key){
        n->right = insert(n->right, key);
    }
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    int balanceFactor = getBalanceFactor(n);

    // LL rotation
    if(balanceFactor > 1 && key < n->left->key){
        rightRotate(n);
    }
    // RR rotation
    if(balanceFactor < -1 && key > n->right->key){
        leftRotate(n);
    }
    // LR rotation
    if(balanceFactor > 1 && key > n->left->key){
        n->left = leftRotate(n->left);
        rightRotate(n);
    }
    // RL rotation
    if(balanceFactor < -1 && key < n->right->key){
        n->right = rightRotate(n->right);
        leftRotate(n);
    }

    return n;

}




int main(){
    return 0;
}