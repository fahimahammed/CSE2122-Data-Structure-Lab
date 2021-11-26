/*Delete an element from a queue.
*/

#include<stdio.h>
#define n 5
int queue[n], front=-1, rear=-1;

///insert element into queue.
void enqueue(int x){
    if((rear+1)%n == front){
        printf("Overflow\n");
    }

    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear]=x;
    }
    else{
        rear = (rear+1)%n;
        queue[rear]=x;
    }
}

///delete element into queue.
void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is Empty\n");
    }
    else if(front == rear){
        printf("Deleted Element: %d\n",queue[front]);
        front = rear = -1;
    }
    else{
        printf("Deleted Element: %d\n",queue[front]);
        front = (front+1)%n;
    }
}

///display element of queue.
void display(){
    int i = front;
    if(front == -1 && rear == -1){
        printf("Queue is Empty\n");
    }
    else if(front == rear){
        printf("Queue is- %d \n",queue[front]);
    }
    else{
        printf("Queue is- ");
        while(i != rear){
            printf("%d ",queue[i]);
            i = (i+1)%n;
        }
        printf("%d \n",queue[rear]);
    }
}
int main(){
    display();
    printf("\n");
    enqueue(1);
    enqueue(2);
    display();
    printf("\n");
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    printf("\n");
    enqueue(6);
    dequeue();
    display();
    printf("\n");
    dequeue();
    display();
    printf("\n");
    enqueue(31);
    enqueue(41);
    enqueue(51);
    display();
    printf("\n");
    return 0;
}
