/*Deleting:
a) Delete Karim from a sorted array. b) Delete an Item from position 2.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char array[20][100];
int n;
void printArray(char arr[][100], int n);
int deleteElementByPosition(char arr[][100], int n, int pos);
int deleleElement(char arr[][100], int n);

int main()
{
    int pos;
    printf("Enter the total number of element: ");
    scanf("%d", &n);

    printf("Enter %d number of string: ", n);

    for(int i=0; i<n; i++){
        scanf("%s", &array[i]);
    }
    int select, x = 1;
    while(x != 0){
        printf("\nOptions:\n  1. Delete element by position\n  2. Delete element\n  0. Exit\nEnter your choice: ");
        scanf("%d", &select);
        switch(select)
        {
            case 0:
                x = 0;
                break;
            case 1:
                printf("\n Enter the position : ");
                scanf("%d", &pos);
                n = deleteElementByPosition(array, n, pos);
                break;

            case 2:
                n = deleleElement(array, n);
                break;

            default:
                printf("Please enter valid input");
            }
    }
    return 0;
}

void printArray(char arr[][100], int n)
{
    for(int i=0; i<n; i++){
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int deleteElementByPosition(char arr[][100], int n, int pos)
{
    int i;
    for(i=pos; i<n-1; i++){
        strcpy(arr[i], arr[i+1]);
    }
    n = n-1;
    printArray(arr, n);
    return n;
}

int deleleElement(char arr[][100], int n)
{
    char value[20];
    printf("Enter a string that you want to delete: ");
    scanf("%s", &value);
    int pos;
    for(int i=0; i<n; i++){
        if(strcmp(value, arr[i]) == 0){
            pos = i;
            //printf("%d", i);
            n = deleteElementByPosition(arr, n, pos);
        }
    }
    return n;
}
