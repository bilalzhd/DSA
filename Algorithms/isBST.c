// PreOrder, PostOrder and Inorder Traversal in a Binary Tree

#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int isBST(struct Node* root){
    static struct Node* prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    } else {
        return 1;
    }
}

struct Node* createNode(int data){
    struct Node* n;
    n = (struct Node*) malloc (sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
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

    printf("%d ", isBST(p));
    return 0;
}