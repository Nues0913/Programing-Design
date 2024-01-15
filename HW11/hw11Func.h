#ifndef HW11Func_H
#define HW11Func_H
struct prefix{
    unsigned ip;
    unsigned char len;
    struct prefix *next; 
};
struct prefix *sort(struct prefix *head);
void Insert(struct prefix** head,unsigned newIP,unsigned char newLen);
// void prefix_insert(struct prefix** targetHead,const char* PATH);
void prefix_insert(struct prefix** targetHead,struct prefix *insertNode);
void prefix_delete(struct prefix** targetHead,struct prefix *deleteNode);
int Len(struct prefix *head);
void PrintLinkedList(struct prefix* head);
void input(struct prefix** head,const char* PATH);
void lenth_distribution(struct prefix *head);
struct prefix **segment(struct prefix *head,int d);
int search(struct prefix *head,struct prefix *node);
#endif