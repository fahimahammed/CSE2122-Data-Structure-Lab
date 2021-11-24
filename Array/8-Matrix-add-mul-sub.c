/* Matrix: Addition/Subtraction/Multiplication of two matrices. */

#include<stdio.h>
#include<stdlib.h>

int mat1[20][20], mat2[20][20], row1, row2, col1, col2;

// input matrix function
void inputMatrix(int row, int col, int mat[20][20])
{
    int i, j;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            scanf("%d", &mat[i][j]);
        }
    }
}

// print matrix function
void printMat(int row, int col, int mat[20][20])
{
    int i, j;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            printf(" %d\t", mat[i][j]);
        }
        printf("\n");
    }
}

// multiplication of two matrix
void matMul(int r1, int c1, int r2, int c2, int mat1[20][20], int mat2[20][20])
{
    int mul[20][20], sum = 0, i, j, k;
    for(i=0; i<r1; i++){
        for(j =0; j<c2; j++){
            for(k=0; k<r2; k++){
                sum = sum + mat1[i][k] * mat2[k][j];
            }
            mul[i][j] = sum;
            sum =0;
        }
    }
    printMat(r1, c2, mul);
}

// addition of two matrix
void addMat(int row, int col, int mat1[20][20], int mat2[20][20])
{
    int sumMat[20][20],i,j;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            sumMat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printMat(row, col, sumMat);
}

// subtraction of two matrix
void subMat(int row, int col, int mat1[20][20], int mat2[20][20])
{
    int Mat[20][20],i,j;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            Mat[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    printMat(row, col, Mat);
}


// base function
int main()
{
    printf("Enter 1st matrix row & column number: ");
    scanf("%d %d", &row1, &col1);

    printf("\nEnter 2nd matrix row & column number: ");
    scanf("%d %d", &row2, &col2);

    if((col1 != row2) && (col1 != col2) && (row1 != row2)){
        printf("\nMatrix multiplication, addition and subtraction is not possible.\n");
        exit(0);
    }
    else if((col1 != col2) && (row1 != row2)){
        printf("\n Matrix addition and subtraction in not possible.\n");

        if(col1 == row2){
            printf("\n Matrix multiplication is possible.\n");

            printf("\nEnter 1st matrix elements\n");
            inputMatrix(row1, col1, mat1);

            printf("\nEnter 2nd matrix elements\n");
            inputMatrix(row2, col2, mat2);

            printf("\n Multiplication of 2 matrix\n");
            matMul(row1, col1, row2, col2, mat1, mat2);
        }
    }
    else if(col1 != row2){

        printf("\nMatrix multiplication is not possible.\n");

        if((col1 == col2) && (row1 == row2)){
            printf("\n Matrix addition and subtraction is possible\n");

            printf("\nEnter 1st matrix elements\n");
            inputMatrix(row1, col1, mat1);

            printf("\nEnter 2nd matrix elements\n");
            inputMatrix(row2, col2, mat2);

            printf("\n Addition of 2 matrix\n");
            addMat(row1, col1, mat1, mat2);
            printf("\n Subtraction of 2 matrix\n");
            subMat(row1, col1, mat1, mat2);
        }
    }
    else{
        printf("\nEnter 1st matrix elements\n");
        inputMatrix(row1, col1, mat1);

        printf("\nEnter 2nd matrix elements\n");
        inputMatrix(row2, col2, mat2);

        printf("\n Addition of 2 matrix\n");
        addMat(row1, col1, mat1, mat2);

        printf("\n Subtraction of 2 matrix\n");
        subMat(row1, col1, mat1, mat2);

        printf("\n Multiplication of 2 matrix\n");
        matMul(row1, col1, row2, col2, mat1, mat2);
    }
}
