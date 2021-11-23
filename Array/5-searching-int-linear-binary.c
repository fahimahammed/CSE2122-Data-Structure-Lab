/*Searching:
Search for 77 using Linear/Binary Search.
*/

#include<stdio.h>
#include<stdlib.h>

void linearSearch(int arr[], int n, int search);
void binarySearch(int arr[], int n, int search);

int main()
{
    int array[100], i, n, searchNum, select;

    printf(" Enter the total number of element: ");
    scanf("%d", &n);

    printf("\n Enter %d number of elements: ", n);
    for(i =0; i<n; i++){
        scanf("%d", &array[i]);
    }

    printf("\n Enter number that you want to search: ");
    scanf("%d", &searchNum);

    printf("\n Select a method of searching\n");
    printf("\n  1. Linear Search\n  2. Binary Search\nEnter your choice: ");
    scanf("%d", &select);

    switch(select)
    {
        case 1:
            linearSearch(array, n, searchNum);
            break;

        case 2:
            binarySearch(array, n, searchNum);
            break;

        default:
            printf("\n Please enter valid number.\n");
            break;
    }


    return 0;
}

void linearSearch(int arr[], int n, int search)
{
    int i;
    for(i=0; i<n; i++){
        if(arr[i] == search){
            printf("\n %d is FOUND at index array[%d].\n", search, i);
            break;
        }
    }
    if(i == n){
        printf("\n %d is NOT FOUND.\n", search);
    }
}
void binarySearch(int arr[], int n, int search)
{
    int start, end, mid, i;
    start = 0;
    end = n-1;
    mid = (start + end)/2;

    while(start <= end){
        if(arr[mid] > search){
            end = mid - 1;
        }
        else if(arr[mid] == search){
            printf("\n %d is FOUND at index array[%d]\n", search, mid);
            break;
        }
        else{
            start = mid + 1;
        }

        mid = (start + end) / 2;
    }
    if(start > end){
        printf("\n %d in NOT FOUND\n", search);
    }
}

