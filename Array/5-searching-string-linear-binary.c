/* Searching:
Search for Karim using Linear/Binary Search
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void linearSearch(char arr[][50], int n, char search[]);
void binarySearch(char arr[][50], int n, char search[]);

int main()
{
   char array[10][50], searchStr[10];
   int n, i, select;
   printf(" Enter total number of element: ");
   scanf("%d", &n);

   printf("Enter %d number of String: ", n);
   for(i = 0; i<n; i++){
        scanf("%s", &array[i]);
   }

   //for(i=0; i<n; i++){
    //printf("%s ", array[i]);
   //}

   printf("\n\n Enter a string that you want to search: ");
   scanf("%s", &searchStr);

   printf("\n Select a method of searching\n");
   printf("\n  1. Linear Search\n  2. Binary Search\nEnter your choice: ");
   scanf("%d", &select);

    switch(select)
    {
        case 1:
            linearSearch(array, n, searchStr);
            break;

        case 2:
            binarySearch(array, n, searchStr);
            break;

        default:
            printf("\n Please enter valid number.\n");
            break;
    }

   return 0;
}

void linearSearch(char arr[][50], int n, char search[])
{
    int i;
    for(i=0; i<n; i++){
        if(strcmp(search, arr[i]) == 0){
            printf("\n \"%s\" is FOUND at array[%d].\n", search, i);
            break;
        }
    }
    if(i == n){
        printf("\n \"%s\" is NOT FOUND.\n", search);
    }
}

void binarySearch(char arr[][50], int n, char search[])
{
    int start, end, mid, i;
    start = 0;
    end = n-1;
    mid = (start + end)/2;

    while(start <= end){
        if(strcmp(search, arr[mid]) > 0){
            start = mid + 1;
        }
        else if(strcmp(search, arr[mid]) == 0){
            printf("\n \"%s\" is FOUND at array[%d].\n", search, mid);
            break;
        }
        else{
            end = mid - 1;
        }
        mid = (start + end)/2;
    }
    if(start > end){
        printf("\n \"%s\" is NOT FOUND.\n", search);
    }
}

