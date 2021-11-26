/*Calculate the factorial of a given number using recursive technique.
*/

#include<stdio.h>

int factorial(int n)
{
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        return factorial(n-1)*n;
    }
}

int main()
{
    int num;
    printf("Enter a num: ");
    scanf("%d", &num);

    printf("\nFactorial of %d is: %d \n", num, factorial(num));
    return 0;
}
