/*Find the value of a Arithmetic expression P written in Postfix notation.
*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 100
int stack[MAX], top = -1;


void push(int n)
{
    stack[++top] = n;
}


int pop()
{
    return stack[top--];
}


void evaluatePostfix(char exp[])
{
    char *e;
    int A, B, value, num;

    e=exp;
    while(*e != NULL){
        if(isdigit(*e)){
            num = *e - 48;
            push(num);
        }
        else{
            A = pop();
            B = pop();

            switch(*e){
                case '+':
                    value = A + B;
                    break;
                case '-':
                    value = B - A;
                    break;
                case '*':
                    value = A * B;
                    break;
                case '/':
                    value = B / A;
                    break;
                case '^':
                    value = pow(B, A);
                    break;
            }
            push(value);
        }
        e++;
    }
    printf("\n Result: %d\n", pop());
}


int main()
{
    char exp[MAX];
    printf("Enter your postfix expression: ");
    scanf("%s", &exp);

    evaluatePostfix(exp);
    return 0;
}
