/* Sorting:
Sort int data using Bubble sort.
*/

#include<stdio.h>

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n)
{
    int i,j, temp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printArray(arr, n);
}

int main()
{
    int array[100], n;
    printf("Enter total number of element: ");
    scanf("%d", &n);

    printf("\nEnter %d number of elements: ", n);
    for(int i=0; i<n; i++){
        scanf("%d", &array[i]);
    }

    printf("\n Before sorting: ");
    printArray(array, n);

    printf("\n After sorting: ");
    bubbleSort(array, n);
    return 0;
}
