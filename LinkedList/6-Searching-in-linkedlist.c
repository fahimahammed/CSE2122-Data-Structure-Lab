/*Searching in linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
} *head;

void createList(int n);
void printList();
void searchItem(int item);

int main()
{
    int n, item;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    createList(n);
    printf("\n Given List: ");
    printList();

    printf("\n\n Enter a number that you searching: ");
    scanf("%d", &item);
    searchItem(item);
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

void searchItem(int item)
{
    struct node *temp;
    int data, c=0;
    if(head == NULL){
        printf("\n List is empty\n");
        exit(0);
    }

    temp = head;
    while(temp != NULL){
        data = temp->data;
        if(item == data){
            printf("\n %d is FOUND.\n", item);
            c = 1;
            break;
        }
        temp = temp->next;
    }
    if(c == 0){
        printf("\n %d is NOT FOUND.\n", item);
    }
}

