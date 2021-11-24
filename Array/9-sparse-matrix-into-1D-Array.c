/* Sparse Matrix: Store the element of a Triangular matrix A into a 1D array B and locate the elements A32 in the array B. */

#include<stdio.h>

int main()
{
    int A[10][10], B[100], row, col, i, j, k=0, searchRow, searchCol;
    printf("Enter the number of row of sparse matrix: ");
    scanf("%d", &row);

    printf("\nEnter the number of column of sparse matrix: ");
    scanf("%d", &col);

    printf("\nEnter your sparse matrix: ");
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            scanf("%d", &A[i][j]);
        }
    }

    //convert into 1D array
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            if(A[i][j] != 0){
                B[k] = A[i][j];
                k++;
            }
        }
    }


    printf("\n Given Sparse Matrix\n");
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            printf(" %d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\n 1D array (Row wise)\n");
    for(i=0; i<k; i++){
        printf(" %d ", B[i]);
    }

    printf("\n Enter row and col number of an element of sparse matrix that you want to find at 1D array(B): ");
    scanf("%d %d", &searchRow, &searchCol);

    for(i = 0; i<k; i++){
        if(B[i]==A[searchRow][searchCol]){
            printf("\n A[%d][%d] element is found at B[%d]\n", searchRow, searchCol, i);
            break;
        }
    }
    if(i == k){
        printf("\n A[%d][%d] element is not found at B\n", searchRow, searchCol);
    }
    return 0;
}
