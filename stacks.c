#include <stdio.h>

typedef struct element{
    
    int val;
    
    struct element *next;
    
}elem;

elem* stack = NULL;

void push(int x){
    elem* temp = malloc(sizeof(elem*));
    
    temp->val = x;
    
    temp->next = stack;
    
    stack = temp;
    
}

void pop(){
    
    elem *temp = stack;
    
    stack = stack->next;
    
    free(temp);
    
}

int isEmpty

int main()
{

    int n;
    
    stack = malloc(sizeof(elem) * n);



    free(stack);
    
    return 0;
}
