#include<stdio.h>
#include<stdlib.h>
struct prefix{
	int data;
	struct prefix *next; 
};
void Insert(struct prefix** head,int newData){
	struct prefix *newNode = (struct prefix*)malloc(sizeof(struct prefix));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;

}
void Reverse(struct prefix** head){
    struct prefix *prev,*cur,*n;
    prev = NULL;
    cur = *head;
    n = cur->next;
    while(cur != NULL){
        n = cur->next;
        cur->next = prev;
        prev = cur;
        cur = n;
    }
    *head = prev;
    
    
}
void printLinkedList(struct prefix* head){
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main()
{
    struct prefix *head = NULL;
	
    Insert(&head,3);
    Insert(&head,7);
    Insert(&head,10); 
    
    
    printf("before:\n");
    printLinkedList(head);
	
    printf("after:\n");
    Reverse(&head);
    printLinkedList(head);
}