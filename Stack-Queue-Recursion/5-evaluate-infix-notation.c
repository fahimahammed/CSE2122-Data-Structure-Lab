/*Find the value of an Arithmetic expression I written in Infix notation.*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 50
int stackNum[MAX], topNum = -1, topOp = -1;
char stackOp[MAX];

void pushNum(int x)
{
    stackNum[++topNum] = x;
}

void pushOp(char ch)
{
    stackOp[++topOp] = ch;
}

int popNum()
{
    return stackNum[topNum--];
}

char popOp()
{
    return stackOp[topOp--];
}

int eval(int num[50], char op[50])
{
    int x, y;
    char ope;
    x = popNum();
    y = popNum();

    ope = popOp();

    switch(ope)
    {
        case '+':
            return x+y;
        case '-':
            return y-x;
        case '*':
            return x*y;
        case '/':
            if(x == 0){
                printf("\n Can not divided by 0.\n");
                exit(0);
            }
            else{
                return y/x;
            }
    }
    return 0;
}

int is_operator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char c)
{
    switch(c)
    {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}


int evaluateInfix(char exp[])
{
    int i, num, output, r;
    char c;
    for(i=0; exp[i] != NULL; i++){
        c = exp[i];
        if(isdigit(c) != 0){
            num = 0;
            while(isdigit(c)){
                num = num*10+(c-'0');
                i++;
                if(i<strlen(exp)){
                    c = exp[i];
                }
                else
                    break;
            }
            i--;
            pushNum(num);
        }
        else if(c == '('){
            pushOp(c);
        }
        else if(c == ')' ){
            while(stackOp[topOp] != '(' ){
                r = eval(stackNum, stackOp);
                pushNum(r);
            }
            popOp();
        }
        else if(is_operator(c)){
            while(topOp != -1 && precedence(c)<=precedence(stackOp[topOp])){
                output = eval(stackNum, stackOp);
                pushNum(output);
            }
            pushOp(c);
        }
    }
    while(topOp != -1){
        output = eval(stackNum, stackOp);
        pushNum(output);
    }
    return popNum();
}

int main()
{
    char exp[MAX];
    printf("Enter your infix expression: ");
    scanf("%s", &exp);

    printf("\n Result: %d\n", evaluateInfix(exp));

    return 0;
}
