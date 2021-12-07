/*Write a program to delete an element from the heap.
*/

#include<stdio.h>

int heap[100], n;

void insertNum(int num, int loc);
void deleteNum(int num);
void display();

int main()
{
   int select, num;
   n = 0;
   while(1){
       printf("\n Select a option\n");
       printf("1.Insert the element \n");
       printf("2.Delete the element\n");
       printf("3.Display all elements \n");
       printf("0.Quit \n");
       printf("Enter your choice : ");
       scanf("%d", &select);

       switch(select){
           case 1:
                printf("\nEnter the element to be inserted to the heap: ");
                scanf("%d", &num);
                insertNum(num, n);
                n++;
                break;

           case 2:
                printf("Enter a number that your want to delete: ");
                scanf("%d", &num);
                deleteNum(num);
                break;

           case 3:
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

void insertNum(int num, int loc)
{
    int parentNode;
    while(loc > 0){
        parentNode = (loc - 1)/2;
        if(num <= heap[parentNode]){
            heap[loc] = num;
            return;
        }
        heap[loc] =  heap[parentNode];
        loc = parentNode;
    }
    heap[0] = num;
}

void display()
{
    int i;
    if(n == 0){
        printf("\nHeap is empty\n");
        return;
    }
    for(i=0; i<n; i++){
        printf(" %d ", heap[i]);
    }
}

void deleteNum(int num)
{
    int left, right, i, temp, parentNode;

    for(i=0; i<n; i++){
        if(num == heap[i]){
            break;
        }
    }

    if(num != heap[i]){
        printf("\n%d is not found in the heap.\n");
        return;
    }

    heap[i] = heap[n-1];
    n = n - 1;

    parentNode = (i-1)/2;

    if(heap[i] > heap[parentNode]){
        insertNum(heap[i], i);
        return;
    }

    left = 2*i + 1;
    right = 2*i - 2;

    while(right < n){
        if(heap[i] >= heap[left] && heap[i] >= heap[right]){
            return;
        }
        if(heap[right] <= heap[left]){
            temp = heap[i];
            heap[i] = heap[left];
            heap[left] = temp;
            i = left;
        }
        else{
            temp = heap[i];
            heap[i] = heap[right];
            heap[right] = temp;
            i = right;
        }

    }
    if(left == n-1 && heap[i]){
        temp = heap[i];
        heap[i] = heap[left];
        heap[left] = temp;
    }
}
