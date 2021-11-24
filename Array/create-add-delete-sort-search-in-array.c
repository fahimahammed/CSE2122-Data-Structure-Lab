#include<stdio.h>

void printArray(int arr[], int length)
{
    printf("\n---------------------------------------\n  Elements: ");
    for(int i=0; i<length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n---------------------------------------\n");
}

int searchElement(int arr[], int length, int searchNum)
{
    int i;
    for(i=0; i<length; i++){
        if(arr[i] == searchNum){
            return i;
            break;
        }
    }
    if(i == length){
        return i;
    }
}

void sortElements(int arr[], int length)
{
    int i, j, temp;
    for(i=0; i<length-1; i++){
        for(j=0; j<length - i - 1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
          }
        }
    }
    printArray(arr, length);
}

int deleteElement(int arr[], int length)
{
    int deleteNum, pos;
    printf("\n Enter a number that you want delete: ");
    scanf("%d", &deleteNum);

    pos = searchElement(arr, length, deleteNum);

    if(pos < length){
        for(int i = pos; i<length-1; i++){
            arr[i] = arr[i+1];
        }
        printArray(arr, length-1);
        return length;
    }
    else if(pos == length){
        printf("\n  Your deleted number is not found at the collection or Empty Collection.\n");
    }
}

int main()
{
    int array[100], n, select, search, x, y;
    printf(" Enter the length of elements: ");
    scanf("%d", &n);

    printf("\n Enter elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &array[i]);
    }

    printArray(array, n);

    y = 1;
    while(y != 0){
        printf("\n Select a option:\n\t1. Search a element\n\t2. Sort a element\n\t3. Delete a element\n\t0. Exit\n");
        printf(" Enter your selected option num: ");
        scanf("%d", &select);

        switch(select)
        {
            case 1:
                printf("\n Enter a number that you want to search: ");
                scanf("%d", &search);
                x = searchElement(array, n, search);
                if(x < n ){
                    printf("\n---------------------------------------\n  %d is Found at position %d\n---------------------------------------\n",search, x);
                }
                else{
                    printf("\n---------------------------------------\n  %d is Not Found\n---------------------------------------\n", search);
                }
                break;

            case 2:
                sortElements(array, n);
                break;

            case 3:
                n = deleteElement(array, n);
                n--;
                break;

            case 0:
                y = 0;
                break;

            default:
                printf("\n  Please enter correct value!\n");
        }
    }

    return 0;
}
