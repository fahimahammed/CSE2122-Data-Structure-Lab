/*Push item into stack*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int stack[MAX], top = -1;

void push(int item)
{
    if(top == MAX-1){
        printf("\n OVERFLOW.\n");
    }
    else{
        top = top + 1;
        stack[top] = item;
        printf("\n %d is pushed in stack.\n", item);
    }
}

void show()
{
    printf("\n      STACK: \n");
    for(int i=top; i>=0; i--){
        printf("\t%d\n", stack[i]);
    }
}

int main()
{
    push(5);
    push(4);
    push(3);
    push(2);
    push(7);
    push(2);
    push(7);
    push(2);
    show();
    return 0;
}
