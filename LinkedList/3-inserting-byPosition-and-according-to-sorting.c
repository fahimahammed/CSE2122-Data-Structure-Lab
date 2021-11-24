#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;

void createList(int n);
void printList();
void insertAccSort(int n);

int main()
{
    int n;
    printf("Enter total number of nodes: ");
    scanf("%d", &n);

    createList(n);
    printList();
    insertAccSort(n);
    return 0;
}

void createList(int n)
{
    struct node *temp, *newNode;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if (head == NULL){
        printf("Unable to access memory.\n");
        exit(0);
    }

    printf("\n Enter the data of node 1 : ");
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
        printf(" Enter the data of node %d : ", i);
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
        printf("List is Empty!\n");
        exit(0);
    }
    temp = head;
    printf("\n List: ");
    while(temp != NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAccSort(int n)
{
    struct node *temp, *newNode;
    int value, i, tmp, loc=1;
    printf("\n Enter a number that you want to insert at sorted list: ");
    scanf("%d", &value);

    temp = head;
    for(i=1; i<=n; i++){
        //printf(" %d ", temp->data);
        tmp = temp->data;
        if(value > tmp){
            loc++;
            //newNode = (struct node *)malloc(sizeof(struct node));
            //newNode->data = value;
            //newNode->next = temp->next;
            //temp->next = newNode;
        }
        temp = temp->next;
        printf("loc: %d\n", loc);
    }

    for(i=1; i<=loc; i++){
        if(i == loc){
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
        }
        temp = temp->next;
    }
    printf("loc: %d\n", loc);
    printList();
}


