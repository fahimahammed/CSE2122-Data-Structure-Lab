#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;

void createList(int n);
void printList();

int main()
{
    int n;
    printf("Enter total number of nodes: ");
    scanf("%d", &n);

    createList(n);
    printf("\n\n LInked List\n");
    printList();
    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Unable to access memory.\n");
        exit(0);
    }

    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;

    temp = head;
    for(i=2; i<=n; i++){
        newNode = (struct node *)malloc(sizeof(struct node));

        if(newNode == NULL){
            printf("Unable to access memory.\n");
            exit(0);
        }

        printf("Enter the data of node %d: ", i);
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
        printf("List is empty!\n");
        exit(0);
    }

    temp = head;
    while(temp != NULL){
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}
