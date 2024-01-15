#include<stdio.h>
#include<stdlib.h>

struct prefix{
    int data;
    struct prefix *next; 
};
void Insert(struct prefix** head,int newData){
    struct prefix* newNode = (struct prefix*)malloc(sizeof(struct prefix));
	
    newNode->data = newData;
    newNode->next = *head;
    
    *head = newNode;
}

void Delete(struct prefix** head,int delData)
{
	struct prefix *cur , *prev = NULL;
	cur = *head;
	
	while(cur!=NULL)
	{
		if(cur->data==delData)
			break;
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	if(cur != NULL)	//有找到Data
	{
		if(prev != NULL)//位置不是head
		{
			prev->next = cur->next;
		} 
		else            //位置為head
			*head =  cur->next;
	}
	free(cur);
}
void printLinkedList(struct prefix* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main()
{
    struct prefix *head=NULL;
    int i,del_num;
    
    for(i=0;i<10;i++)
	{
            Insert(&head,i);
	}
    printLinkedList(head);
	
    printf("Enter del_num:");
    scanf("%d",&del_num);	
    Delete(&head,del_num);
    printLinkedList(head);
	
}