/*Insert an element into a queue.*/

#include<stdio.h>
#define MAX 5

int queueArray[MAX], front=-1, rear = -1;

void enqueue()
{
    if(rear == MAX-1){
        printf("\n OVERFLOW\n");
    }
    else{
        if(front == -1){
            front = 0;
        }
        printf("\n Enter a number: ");
        scanf("%d", &queueArray[++rear]);
    }

}
void display()
{
    int i;
    if (front == - 1)
        printf(" Queue is empty \n");
    else
    {
        printf(" Queue is : \n");
        for (i = front; i <= rear; i++){
            printf("%d ", queueArray[i]);
        }
        printf("\n");
    }
}
int main()
{
    enqueue();
    enqueue();
    enqueue();
    display();
    enqueue();
    display();
    return 0;
}
