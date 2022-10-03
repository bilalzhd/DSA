#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int size;
    int top;
    char* arr;
};
int stackTop(struct Stack * ptr){
    return ptr->arr[ptr->top];
}
int isEmpty(struct Stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}
int isFull(struct Stack * ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    return 0;
}
int push(struct Stack * ptr, char val){
    if(!isFull(ptr)){
        ptr->top++;
        ptr->arr[ptr->top] = val;
        return 1;
    }
    return 0;
}
char pop(struct Stack * ptr){
    if(!isEmpty(ptr)){
        int top = ptr->arr[ptr->top];
        ptr->top--;
        return top;
    }
    else {
        printf("The stack is already empty");
    }
}
int precedence(char ch){
    if(ch == '*' || ch == '/')
        return 3;
    
    else if(ch == '+' || ch == '-')
        return 2;
    
    else
    return 0;
}
int isOperator(char ch){
    if(ch == '*' || ch == '+' || ch == '-' || ch == '/' ){
        return 1;
    }
    return 0;
}
char * infixToPostfix(char * infix){
    struct Stack * sp = (struct Stack *) malloc (sizeof(struct Stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    int i = 0;
    int j = 0;
    char * postfix = (char *) malloc ((strlen(infix) + 1) * sizeof(char));
    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++; j++;
        } else {
            if(precedence(infix[i]) > precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            } else {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main(){
    char * infix = "x-y/z-k*d";
    printf("Postfix if %s", infixToPostfix(infix));
    return 0;
}