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
    // free(newNode); => error cauz free the memory loc *head's pointing to
}

void Delete(struct prefix** head,int delData){
	struct prefix *cur, *prev = NULL;
	for(cur = *head;cur != NULL && cur->data != delData;prev = cur,cur = cur->next);
    if(cur == NULL) return; //if not found
    if(prev == NULL){
        /*
        if tried to operate on cur
        cur = cur->next; // (X) when adjust whole cur, the address changes but the *head doesn't
        should adjust the struct value instead of itself, notice can't free(cur) otherwise *head would be freed
        cur->data = cur->next->data;
        cur->next = cur->next->next;
        use *head = (*head)->next instead
        */
        *head = (*head)->next;
    } else {
        prev ->next = cur ->next;
    }
    free(cur);
}

void printLinkedList(struct prefix* head){
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main(){
    struct prefix *list = NULL;
    int i,del_num;
    
    for(i=0;i<10;i++){
        Insert(&list,i);
	}
    printLinkedList(list);
	
    printf("Enter del_num:");
    scanf("%d",&del_num);	
    Delete(&list,del_num);
    printLinkedList(list);
	
}