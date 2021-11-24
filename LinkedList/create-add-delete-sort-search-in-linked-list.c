#include<stdio.h>
#include<stdlib.h>

struct node * createLinkedList(int arr[], int n);
int searchInList(struct node *head, int value);


struct node{
    int data;
    struct node *next;
};


int main()
{
    int a[] = {2, 13, 4, 16};
    struct node *head;
    head = createLinkedList(a, 4);
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("index; %d\n", searchInList(head, 2));
    return 0;
}

int searchInList(struct node *head, int x){
    int index = 1;
    while(head != NULL){
        if (head->data == x){
            return index;
        }
        index++;
        head = head->next;
    }
    return -1;

}

struct node * createLinkedList(int arr[], int n)
{
    int i;
    struct node *head = NULL, *temp = NULL, *current=NULL;

    for(i=0; i<n; i++){
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->next = NULL;

        if(head == NULL){
            head = temp;
            current = temp;
        }
        else{
            current->next = temp;
            current = current->next;
        }

    }
    return head;
}
