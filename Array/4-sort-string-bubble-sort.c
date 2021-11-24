/*Sorting:
Sort integer data using Bubble sort.
*/

#include <stdio.h>
#include <string.h>

void sortElement(char arr[][50], int n);

int main()
{
    char array[10][50];
    int n;
    printf("Enter total number of element: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(int i=0; i<n; i++){
        scanf("%s", &array[i]);
    }

    printf("\n Elements: ");
    for(int i=0; i<n; i++){
        printf("%s ", array[i]);
    }

    sortElement(array, n);
}

void sortElement(char arr[][50], int n)
{
    char temp[10];
    int i, j;
    for(i = 1; i<=n; i++){
        for(j=0; j<n-i; j++){
            if(strcmp(arr[j], arr[j+1])>0){
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
    printf("\n\n Sorted Elements: ");
    for(i =0; i<n; i++){
        printf("%s  ", arr[i]);
    }
    printf("\n");
}
