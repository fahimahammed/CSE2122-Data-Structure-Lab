/*Take adjacency matrix with m nodes as input and calculate Br and from that calculate Path Matrix and tell whether the matrix is strongly connected or not.
*/

#include<stdio.h>
#include<stdlib.h>

int adj[10][10], A[10][10], sum[10][10], n;

void mul();
void printMat(int mat[10][10]);
void checkStrong();

int main()
{
    int i, j, k;
    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("\n Enter %d x %d matrix elements: \n", n, n);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &adj[i][j]);
            sum[i][j] = 0;

            if(i==j){
                A[i][j] = 1;
            }
            else{
                A[i][j] = 0;
            }
        }
    }

    for(i=0; i<n; i++){
        mul();      // find a1, a2, a3..... an;
        for(j=0; j<n; j++){
            for(k=0; k<n; k++){
                sum[j][k] = sum[j][k] + A[j][k];    // sum for find B.
            }
        }
    }

    //printf("\n");
    //printMat(A);

    // find the matrix of Bn
    printf("\n B matrix: \n");
    printMat(sum);

    printf("\n STATUS: ");
    checkStrong();
    return 0;
}

void mul()
{
    int i, j, k, b[10][10];
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){

            b[i][j] = 0;

            for(k=0; k<n; k++){
                b[i][j] = b[i][j] + adj[i][k] * A[k][j];
            }
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            A[i][j] = b[i][j];
        }
    }
}

void printMat(int mat[10][10])
{
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }
}

void checkStrong()
{
    int i, j, c=0;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(sum[i][j] == 0){
                c++;
            }
        }
    }
    if(c > 0){
        printf(" The graph is not strongly connected.\n");
    }
    else{
        printf(" The graph is strongly connected.\n");
    }
}

