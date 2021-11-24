/*Inserting: Insert
Rahim to a sorted array ,Karim to position 5.*/

#include<stdio.h>
#include <stdlib.h>
#include<string.h>

char array[20][100];
int n;
void sortElement(char arr[][100], int n);
int value(char a[][100], int n);
int index(char a[][100], int n);


int main(){

    printf("Enter Size of array: ");
    scanf("%d",&n);

    printf("Enter Strings of the array: \n");

    for(int i=0;i<n;i++){
        scanf("%s",array[i]);
    }

    int choice;

    while(1){
        printf("\nSelect Option\n");
        printf("1. Sorting elements\n");
        printf("2. Insert String according to sorted list.\n");
        printf("3. Insert String with position\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1: sortElement(array, n);
                    break;
            case 2: n = value(array, n);
                    break;
            case 3: n = index(array, n);
                    break;
            case 0:
                exit(0);
            default:
                printf("Please enter valid input.\n");
        }
    }
    return 0;
}


void sortElement(char arr[][100], int n){

    char temp[100];

    for(int i=0; i< n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(strcmp(arr[j], arr[min]) < 0){
                min=j;
            }
        }
        if(min != i){
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[min]);
            strcpy(arr[min], temp);
        }
    }
    for(int i=0;i<n;i++){
        printf("%s\n",arr[i]);
    }

}

int value(char arr[][100], int n){

    char item[100];
    int position;
    printf("\nEnter String to be inserted: ");
    scanf("%s", item);

    for(int i=0;i<n;i++){

        if (strcmp(item, arr[i])<0){
            position = i;
            break;
        }else{
            position = i+1;
        }
    }

    for(int j=n+1; j>=position; j--){
            strcpy(arr[j], arr[j-1]);
    }
    strcpy(arr[position], item);
    n=n+1;

    printf("\nAfter inserted:  ");
    for(int k=0;k<n;k++){
        printf(" %s ", arr[k]);
    }
    return n;
}


int index(char arr[][100], int n){

    int indexValue;
    char item[100];

    printf("\nEnter index no. to insert the data: ");
    scanf("%d",&indexValue);
    printf("Enter data to be inserted: ");
    scanf("%s",item);

    for(int j=n+1 ;j>=indexValue; j--){
            strcpy(arr[j],arr[j-1]);
    }
    strcpy(arr[indexValue-1], item);
    n=n+1;
    printf("\nAfter inserted: ");
    for(int i=0; i<n; i++){
        printf(" %s ",arr[i]);
    }
    return n;
}
