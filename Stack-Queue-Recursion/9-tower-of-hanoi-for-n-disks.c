/*Solve Towers of Hanoi problem for N disks.*/

#include<stdio.h>

void towers(int num, char from, char to, char aux)
{
    if(num == 1){
        printf("\n Move disk 1 from %c to %c.", from, to);
        return;
    }
    towers(num - 1, from, aux, to);
    printf("\n Move disk %d from %c to %c.", num, from, to);
    towers(num -1, aux, to, from);
}

int main()
{
    int num;
    printf("Enter the number of disks: ");
    scanf("%d", &num);

    printf("\nThe sequence of moves involved in the tower of Hanoi are- \n");
    towers(num, 'A', 'C', 'B');
    return 0;
}
