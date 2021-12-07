#include<stdio.h>

int W[10][10], A[10][10], n;

void printMat(int mat[10][10]);
void sortestPath();

int main()
{
    int i, j;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    printf("Enter matrix: \n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &W[i][j]);
            if(W[i][j] == 0){
                A[i][j] = 999999;
            }
            else{
                A[i][j] = W[i][j];
            }
        }
    }

    printMat(A);
    printf("\n\n");
    printMat(W);
    printf("\n\n");
    sortestPath();
    printMat(A);
    return 0;
}

void printMat(int mat[10][10])
{
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(mat[i][j] == 999999){
                printf(" %c ", 'X');
            }
            else{
                printf(" %d ", mat[i][j]);
            }
        }
        printf("\n");
    }
}

void sortestPath()
{
    int i, j, k;
    for(k=0; k<n; k++){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(A[i][k]+A[k][j] < A[i][j]){
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
    }

}


