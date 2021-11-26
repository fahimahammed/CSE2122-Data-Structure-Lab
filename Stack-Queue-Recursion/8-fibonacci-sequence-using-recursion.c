/*Calculate the FN of a Fibonacci sequence using recursive technique.*/

#include<stdio.h>

int fibo(int n)
{
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return fibo(n-1)+fibo(n-2);
    }
}

int main()
{
    int num, i;
    printf("Enter a num: ");
    scanf("%d", &num);

    printf("\nFibonacci sequence:\n");
    for(i=0; i<num; i++){
        printf("%d ", fibo(i));
    }
    printf("\n");
    return 0;
}
