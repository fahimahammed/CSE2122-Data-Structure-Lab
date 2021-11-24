/*3. Inserting: a) inset a node in nth position. b) insert a node in sorted list*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;

void createList(int n);
void printList();
void insertAccSort(int n);
void insertByPos(int value, int loc, struct node *head);

int main()
{
    int n, select, value, pos;
    printf("Enter total number of nodes: ");
    scanf("%d", &n);

    createList(n);
    printList();

    printf("\n MENU \n\t1. Insert by postion.\n\t2. Insert according to ascending oreder.\n\t0. Exit\n   Enter your choice: ");
    scanf("%d", &select);
    switch(select)
    {
        case 1:
            printf("\n Enter the position: ");
            scanf("%d", &pos);
            printf("\n Enter the data: ");
            scanf("%d", &value);
            insertByPos(value, pos, head);
            break;

        case 2:
            insertAccSort(n);
            break;

        case 0:
            exit(0);
            break;

        default:
            printf("\n Please enter valid input.\n");
        }

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
        tmp = temp->data;
        if(value > tmp){
            loc++;
        }
        temp = temp->next;

    }
    //printf("loc: %d\n", loc);
    insertByPos(value, loc, head);
}

void insertByPos(int value, int loc, struct node *head1)
{
    struct node *temp, *newNode;
    int i;
    newNode = (struct node *)malloc(sizeof(struct node));

    if(newNode == NULL){
        printf("Unable to allocate memory.\n");
        exit(0);
    }

    newNode->data = value;
    newNode->next = NULL;

    temp = head1;
    for(i=2; i<loc; i++){
        temp = temp->next;
        //temp->next = newNode;
        if(temp == NULL){
            break;
        }
    }
    if(temp != NULL){
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printList();
}


