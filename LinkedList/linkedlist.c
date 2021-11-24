#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;

void createList(int n);
void printList();
int searchList();

int main()
{
    int n, x;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    createList(n);
    printList();
    x = searchList();
    if(x == -1){
        printf("\nNot Found\n");
    }
    else{
        printf("\nFound\n");
    }
    //printf("%d", x);
    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    printf("Enter the value of node 1: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;

    temp = head;
    for(i= 2; i<=n; i++){
        newNode = (struct node *)malloc(sizeof(struct node));
        if(newNode == NULL){
            printf("unable to allocate memory.");
            break;
        }
        printf("Enter the value of node %d: ", i);
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
        printf("Empty\n");
        return;
    }
    temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int searchList()
{
    printf("Enter a number to search: ");
    int searchNum, index=1;
    scanf("%d", &searchNum);

    while(head != NULL){
        if(head->data == searchNum){
            return index;
        }
        index++;
        head = head->next;
    }
    return -1;

    //printList();
}
