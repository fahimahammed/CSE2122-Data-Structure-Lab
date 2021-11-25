/*Sorting a list in linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
} *head;

void createList(int n);
void printList();
void sortList();

int main()
{
    int n;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    createList(n);
    printf("\n Given List: ");
    printList();

    sortList();
    printf("\n Sorted list: ");
    printList();
    printf("\n");
    return 0;
}

void createList(int n)
{
    struct node *temp, *newNode;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL){
        printf("Unable to allocate memory.\n");
        exit(0);
    }

    printf("\n Enter the data of node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;

    temp = head;
    for(i=2; i<=n; i++){
        newNode = (struct node *)malloc(sizeof(struct node));
        if(newNode == NULL){
            printf("Unable to allocate memory\n");
            exit(0);
        }

        printf(" Enter the data of node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
}

void printList()
{
    struct node *temp;
    if(head == NULL){
        printf("\nEmpty List!\n");
        exit(0);
    }
    temp = head;
    while(temp != NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }

}

void sortList()
{
    struct node *current = head, *index = NULL;
    int temp;

    if(head == NULL){
        printf("\nList is empty.\n");
        exit(0);
    }

    while(current != NULL){
        index = current->next;
        while(index != NULL){
            if(current->data > index->data){
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}
