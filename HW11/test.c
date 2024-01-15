#include<stdio.h>
#include<stdlib.h>

struct prefix{
    unsigned ip;
    unsigned char len;
    struct prefix *next; 
};
void Insert(struct prefix** head,unsigned newIP,unsigned char newLen);
void Delete(struct prefix** head,int delData);
int Len(struct prefix *head);
void PrintLinkedList(struct prefix* head);
void input(struct prefix** head,const char* PATH);
void lenth_distribution(struct prefix *head);


void Insert(struct prefix** head,unsigned newIP,unsigned char newLen){
    struct prefix *newNode = (struct prefix*)malloc(sizeof(struct prefix));
    newNode->ip = newIP;
    newNode->len = newLen;
    newNode->next = *head;
    *head = newNode;
}

void Delete(struct prefix** head,int delData){
	struct prefix *cur, *prev = NULL;
	for(cur = *head;cur != NULL && cur->ip != delData;prev = cur,cur = cur->next);
    if(cur == NULL) return; //if not found
    if(prev == NULL){
        *head = (*head)->next;
    } else {
        prev ->next = cur ->next;
    }
    free(cur);
}

/**
 * @brief Return the total number of prefixes in the linkedList.
 * 
 * @param head The linkedList
 * @return int 
 */
int Len(struct prefix *head){
    struct prefix *p;
    int count = 0;
    for(p = head;p != NULL;p = p->next,count++);
    return count;
}

void PrintLinkedList(struct prefix* head){
    while(head != NULL){
        unsigned a,b,c,d;
        a = ((head->ip) >> 24) & 0xFF;
        b = ((head->ip) >> 16) & 0xFF;
        c = ((head->ip) >> 8) & 0xFF;
        d = ((head->ip) >> 0) & 0xFF;
        printf("%d/%d => ", head->ip,head->len);
        printf("%u.%u.%u.%u/%hhu\n", a,b,c,d,head->len);
        printf("%d",(head->ip)>>(32-10));
        head = head->next;
    }
    // printf("NULL\n");
}

/**
 * @brief Read all the prefixes from the input file.
 * 
 * @param head The linkedList's pointer
 * @param PATH File path
 */
void input(struct prefix** head,const char* PATH){
    FILE *file = fopen(PATH, "r");
    unsigned flag,a,b,c,d,ip;
    unsigned char len;
    while ((flag = fscanf(file, "%u.%u.%u.%u/%hhu", &a, &b, &c, &d, &len))!= EOF) {
        if(flag >= 5){
            // printf("%u.%u.%u.%u/%hhu ",a,b,c,d,len);
            ip = (a << 24)|(b << 16)|(c << 8)|d;
            // printf("IP: %d\n",ip);
            Insert(head,ip,len);
        } else {
            len = (d)?32:(c)?24:(b)?16:(a)?8:8;
            // printf("%u.%u.%u.%u/%hhu ",a,b,c,d,len);
            ip = (a << 24)|(b << 16)|(c << 8)|d;
            // printf("IP: %d\n",ip);
            Insert(head,ip,len);
        }
    }
}

/**
 * @brief compute the number of prefixes with prefix length i, for i = 0 to 32
 * 
 * @param head the linkedList
 * @return int 
 */
void lenth_distribution(struct prefix *head){
    struct prefix *p;
    for(int i = 0;i<=32;i++){
        int count = 0;
        for(p = head;p != NULL;p = p->next){
            if(p->len == i) count++;
        }
        if(count != 0) printf("the number of prefixes with prefix length %d = %d\n",i,count);
    }
}



/**
 * @param argv[1] "routing_table.txt"
 * @param argv[2] "inserted_prefixes.txt"
 * @param argv[3] "delete_prefixes.txt"
 * @param argv[4] "trace_file.txt"
 * @param argv[5] "d" use atoi to transform to integer
*/
int main(int argc, char *argv[]){
    struct prefix *routing_table = NULL;
    input(&routing_table,"test.txt");
    PrintLinkedList(routing_table);
    

}