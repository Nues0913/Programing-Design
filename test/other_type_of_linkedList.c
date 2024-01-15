#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct NODE{
    int value;
    struct NODE *next;
} Node;

typedef struct LIST{
    Node *first;
    Node *last;
} List;

Node* newNode (int value, Node *next) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = next;
    return node;
}

void print (List list) {
    Node *node = list.first;
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

void append (List *list, int value) {
    Node *node = newNode(value, NULL);
    if (list->last == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        list->last = node;
    }
}

bool search (List list, Node **prevNode, Node **targetNode, int targetValue) {
    Node *node = list.first;
    while (node != NULL) {
        if (node->value == targetValue) {
            if (targetNode != NULL) {
                *targetNode = node;
            }
            return true;
        }
        if (prevNode != NULL) {
            *prevNode = node;
        }
        node = node->next;
    }
    return false;
}

bool update (List *list, int target, int value) {
    Node *node;
    if (!search(*list, NULL, &node, target)) {
        return false;
    }
    node->value = value;
    return true;
}

bool insert (List *list, int target, int value) {
    Node *prev = NULL, *next = NULL;
    if (!search(*list, &prev, &next, target)) {
        return false;
    }
    Node *node = newNode(value, next);
    if (prev == NULL) {
        list->first = node;
    } else {
        prev->next = node;
    }
    return true;
}

bool deleteNode (List *list, int target) {
    Node *prev = NULL, *node = NULL;
    if (!search(*list, &prev, &node, target)) {
        return false;
    }
    if (prev == NULL) {
        list->first = node->next;
    } else {
        prev->next = node->next;
    }
    free(node);
    return true;
}

void clear (List *list) {
    Node *node = list->first, *next;
    while (node != NULL) {
        next = node->next;
        free(node);
        node = next;
    }
}

void main(){
    List list = {NULL , NULL};
    for(int i = 0;i<10;i++){
        append(&list,i);
    }
    print(list);
}