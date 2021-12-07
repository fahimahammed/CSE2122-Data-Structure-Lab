#include<stdio.h>
#include<stdlib.h>

void BFS(int);
int graph[10][10], visited[10], total;

int main()
{
    int i, j;
    printf("\nEnter the total number of vertices in graph: ");
    scanf("%d", &total);

    printf("\nEnter the value for adj matrix: ");
    for(i=0; i<total; i++){
        for(j=0; j<total; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    for(i=0; i<total; i++){
        visited[i] = 0;
    }

    BFS(0);
}

void BFS(int vertex)
{
    int j;
    printf("%d \t", vertex);
    visited[vertex] = 1;
    for(j=0; j<total; j++){
        if( !visited[j]  && graph[vertex][j]){
            BFS(j);
        }
    }
}

