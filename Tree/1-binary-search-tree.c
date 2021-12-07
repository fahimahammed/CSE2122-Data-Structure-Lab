/*Write a program to insert an element in a Binary search tree; if the element already inserted before then display the location.*/

#include<stdio.h>

int tree[100] = {0};

void insert(int data);
void display();

int main()
{
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(4);
    display();
    return 0;
}

void insert(int data)
{
    int i = 0, root = 0;
    while(1){
        if(tree[i] == data){
            printf("Already in position %d\n", i);
            break;
        }
        else if(tree[i] == 0){
            tree[i] = data;
            break;
        }
        else if(data < tree[i]){
            i = 2*i + 1;
        }
        else if(data > tree[i]){
            i = 2*i + 2;
        }
    }
}

void display()
{
    printf("Index -> Value\n");
    for(int i=0; i<15; i++){
        printf("%d   ->    %d\n", i, tree[i]);

    }
}
