/*3. Inserting: insert a string in sorted list and by position*/
// INCOMPLETE

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

typedef struct stringData {
    char *s;
    struct stringData *next;
} Node;

Node *createNode(char *s) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->s = s;
    newNode->next = NULL;
    return newNode;
}


void insert(Node *head, Node *newNode) {
    if (head == NULL) {
        head->s = newNode->s;
        head = newNode;
    }
}

void printList(Node *head) {
    while (head != NULL) {
        printf("%s\n", head->s);
        head = head->next;
    }
}



int main()
{
    Node *head = createNode(NULL);

    Node *a = createNode("A");
    insert(head, a);

    printList(head);
    return 0;
}
