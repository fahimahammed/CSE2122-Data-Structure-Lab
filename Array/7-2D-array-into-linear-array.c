/*Copy elements of a 2D array into a 1D/linear array and print the elements of group 3 from the 1D array.*/

#include<stdio.h>
#define n 3

void print1DArray(int arr[])
{
    int x = n*n, i;
    for(i=0; i<x; i++){
        printf(" %d ", arr[i]);
    }
}

int main()
{
    int array[n][n], rowArray[n*n], colArray[n*n], i, j, k=0, l=0;
    printf(" Enter 2D array elements (Row = 3, Col=3) \n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &array[i][j]);
        }
    }

    printf("\n\n 2D ARRAY: \n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf(" %d ", array[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            rowArray[k] = array[i][j];
            k++;
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            colArray[l] = array[j][i];
            l++;
        }
    }

    printf("\n\n Linear array (Row wise)\n");
    print1DArray(rowArray);

    printf("\n\n Linear array (Row wise)\n");
    print1DArray(colArray);

    printf("\n");
    return 0;
}
