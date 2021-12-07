/**
Write a program that takes an Adjacent matrix A with m vertices as input and output the following:
A. adjacent of V1, V2,.................,Vm
B. no. of paths of length 2 from Vi to Vj.
C. no. of paths of length 3 from Vi to Vj.
D. no. of paths of length 4 from Vi to Vj.
**/


#include<stdio.h>
#include<stdlib.h>

int adj[20][20], n, mul[20][20];

void adjacentFind();
void multiplication();
void pathLength(int length);

int main()
{
    int i, j, k;
    printf("Enter the total number of vertex: ");
    scanf("%d", &n);

    printf("Enter your adjacent matrix: \n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &adj[i][j]);
            if(i==j){
                mul[i][j] = 1;
            }
            else {
                mul[i][j] = 0;
            }
        }
    }

    printf("\n");
    adjacentFind();

    for(i=1; i<=4; i++){
        multiplication();

        if(i == 2){
            pathLength(2);
        }
        if(i == 3){
            pathLength(3);
        }
        if(i == 4){
            pathLength(4);
        }
    }
    return 0;
}


void adjacentFind()
{
    int i, j;
    printf("\nadjacent of V1, V2,.................,Vm\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(adj[i][j] != 0){
                printf("\tV%d => V%d \n", i+1, j+1);
            }
        }
    }
}

void multiplication()
{
    int i, j, k, res[20][20];
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            res[i][j] = 0;
            for(k=0; k<n; k++){
                res[i][j] = res[i][j] + adj[i][k] * mul[k][j];
            }
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            mul[i][j] = res[i][j];
        }
    }
}

void pathLength(int length)
{
    int j, k;
    printf("\nNo. of paths of length %d from-\n", length);
    for(j=0; j<n; j++){
        for(k=0; k<n; k++){
            if(mul[j][k] != 0){
                printf("\tV%d => V%d\n", j+1, k+1);
            }
        }
    }
}
