/*Find out the Path Matrix of an adjacent matrix with m nodes using Warshall’s Algorithm.*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int A[10][10], P[10][10], n, i, j, k;
    printf("Enter the order of Adjacency matrix: ");
    scanf("%d", &n);

    printf("Enter a %d x %d adjacency matrix: \n",n,n);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &A[i][j]);
            if(A[i][j] != 0){
                P[i][j] = 1;
            }
            else{
                P[i][j] = 0;
            }
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            for(k=0; k<n; k++){
                P[i][j] = P[i][j] + (P[i][k] * P[k][j]);
                if(P[i][j] != 0){
                    P[i][j] = 1;
                }
            }
        }
    }

    printf("\nPath Matrix: \n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf(" %d ", P[i][j]);
        }
        printf("\n");
    }

}
