/*Delete top element into stack*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int stack[MAX], top = -1;

void push(int item)
{
    if(top == MAX-1){
        printf("\n OVERFLOW");
    }
    else{
        top = top + 1;
        stack[top] = item;
        printf("\n %d is pushed in stack.\n", item);
    }
}

void show()
{
    if(top == -1){
        printf("\n Stack is Empty!\n");
    }
    else{
        printf("\nStack:\n");
        for(int i=top; i>=0; i--){
            printf(" %d\n", stack[i]);
        }
    }
}

void pop()
{
    if(top == -1){
        printf("\n UNDERFLOW.\n");
    }
    else{
        printf("\n Pop item: %d\n", stack[top]);
        top--;
    }
}

int main()
{
    push(5);
    show();
    push(3);
    push(4);
    show();
    pop();
    show();
    pop();
    show();
    return 0;
}
