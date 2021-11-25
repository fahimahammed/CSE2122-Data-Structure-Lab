/*deleting item from list*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
} *head;

void createList(int n);
void printList();
void deleteItemByPos(int pos);
void deleteItem();

int main()
{
    int n, item, pos;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    createList(n);
    printList();

    printf("\n Enter the position: ");
    scanf("%d", &pos);
    deleteItemByPos(pos);
    printList();

    printf("\n Enter the item: ");
    scanf("%d", &item);
    deleteItem(item);
    printList();

    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
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
    for(i = 2; i<=n; i++){
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
        printf("\n List is Empty!\n");
        exit(0);
    }

    temp = head;
    while(temp != NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}

void deleteItemByPos(int pos)
{
    struct node *temp, *prvs;
    if(head == NULL){
        printf("\n List is Empty\n");
        exit(0);
    }

    temp = head;
    if(pos == 1){
        printf("\n\n %d is removed from list.\n", head->data);
        head = head->next;
    }else{
        temp = temp->next;
    }

    for(int i=2; i<=pos; i++){
        if(i == pos-1){
            prvs = temp;
        }
        if(i==pos){
            printf("\n\n %d is removed from list.\n", temp->data);
            prvs->next = temp->next;
        }
        temp = temp->next;
    }
}

void deleteItem(int item)
{
    struct node *temp;
    int pos=1, data;
    if(head == NULL){
        printf("\nList is Empty!\n");
        exit(0);
    }

    temp = head;
    while(temp != NULL){
        data = temp->data;
        if(data != item){
            pos++;
            //printf(" %d ", temp->data);
        }
        if(data == item){
            break;
        }
        temp = temp->next;
    }
    deleteItemByPos(pos);
}
