/* Inserting: Insert
54 to a sorted array, 99 to position 5. */


#include<stdio.h>

void printArray(int arr[], int n);
void insertElementToSortedArray(int arr[], int n);
int insertElementByPosition(int arr[], int n, int pos, int value);

int main()
{
    int n, array[100], pos, value, x = 1;
    printf("Enter total number of element: ");
    scanf("%d", &n);

    printf("Enter %d number of elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &array[i]);
    }

    insertElementToSortedArray(array, n);

    printf("\nEnter the position where you want to insert element: ");
    scanf("%d", &pos);
    printf("\nEnter the value you want to insert at position %d : ", pos);
    scanf("%d", &value);
    printArray(insertElementByPosition(array, n, pos, value), n+1);

    return 0;
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++){
        printf(" %d  ", arr[i]);
    }
}

int insertElementByPosition(int arr[], int n, int pos, int value)
{
    int i;
    n = n+1;
    //printf("pos;  %d %d", pos, n);
    for(i = n; i >= pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = value;

    return arr;
}


void insertElementToSortedArray(int arr[], int n)
{
    int value, i, j, temp, pos;
    printf("Enter the value that you want to insert: ");
    scanf("%d", &value);

    for(i = 0; i<n; i++){
        if(value < arr[i]){
           pos = i;
           break;
        }else{
            pos = i+1;
        }
    }

    printf("\nAfter inserted to a sorted array \n");
    printArray(insertElementByPosition(arr, n, pos, value), n+1);
}
