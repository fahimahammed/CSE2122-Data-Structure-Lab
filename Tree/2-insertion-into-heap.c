/*Write a program to insert an element into the heap*/

#include<stdio.h>

int heap[100], n;

void insert(int num, int loc);
void display();

int main()
{
   int select, num;
   n = 0;
   while(1){
       printf("\n Select a option\n");
       printf("1.Insert the element \n");
       printf("2.Display all elements \n");
       printf("0.Quit \n");
       printf("Enter your choice : ");
       scanf("%d", &select);

       switch(select){
           case 1:
                printf("\nEnter the element to be inserted to the heap: ");
                scanf("%d", &num);
                insert(num, n);
                n++;
                break;

           case 2:
                display();
                break;

           case 0:
                exit(0);
                break;

           default:
                printf("\nInvalid choice.\n");
       }
   }

}

void insert(int num, int loc)
{
    int parentNode;
    while(loc > 0){
        parentNode = (loc - 1)/ 2;
        if(num <= heap[parentNode]){
            heap[loc] = num;
            return;
        }
        heap[loc] = heap[parentNode];
        loc = parentNode;
    }
    heap[0] = num;
}

void display()
{
    int i;
    if(n == 0){
        printf("\nHEAP IS EMPTY!\N");
        return;
    }
    for(i=0; i<n; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");

}
