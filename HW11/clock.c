#include<stdlib.h>
#include<stdio.h>
#include"hw11Func.h"

unsigned long long int begin,end;

unsigned long long int rdtsc()//32-bit
{
	unsigned long long int x;
	__asm__   volatile ("rdtsc" : "=A" (x));
	return x;
}

unsigned long long int rdtsc_64bits()//64-bit
{
   unsigned long long int x;
   unsigned a, d;

   __asm__ volatile("rdtsc" : "=a" (a), "=d" (d));

   return ((unsigned long long)a) | (((unsigned long long)d) << 32);;
}

int main(int argc, char *argv[]){
    struct prefix *routing_table = NULL;
    input(&routing_table,argv[1]);
    // input(&routing_table,"C:\\Users\\a0987\\Desktop\\hw\\HW11\\test.txt");
    // PrintLinkedList(routing_table);
    printf("The total number of prefixes in the input file is : %d.\n",Len(routing_table));
    // newSegment is an array stored (struct prefix *) pointers in groups with linkedList
    // struct prefix **newSegment = segment(routing_table,atoi(argv[5]));
    // for(int i = 0;i < (1<<(atoi(argv[5]))) ;i++){
    //     printf("The number of prefixes in group %d = %d\n",i,Len(*(newSegment+i)));
    // }
    // PrintLinkedList(routing_table);
    
    // DO INSERT
    printf("Do insert:\n");
    struct prefix *insert_table = NULL,*sorted_insert_table = NULL,*head;
    input(&insert_table,argv[2]);
    // input(&insert_table,"C:\\Users\\a0987\\Desktop\\hw\\HW11\\testInsert.txt");

    int times = 0;
    // while(times != 1000){

        // begin = rdtsc();
        
        
        sorted_insert_table = sort(insert_table);
        head = sorted_insert_table;
        while(head){
            prefix_insert(&routing_table,head); 
            head = head->next;
        }


        // end = rdtsc();
        // if((end-begin)<1000000000)
        // printf("%llu\n",(end-begin));
        // times++;
    // }

    // printf("The total number of prefixes in the input file is : %d.\n",Len(routing_table));
    // printf("Execute cycles %llu \n",(end-begin));
    // PrintLinkedList(routing_table);

    //DO DELETE
    printf("Do delete:\n");
    struct prefix *delete_table = NULL;
    input(&delete_table,argv[3]);
    // input(&delete_table,"C:\\Users\\a0987\\Desktop\\hw\\HW11\\testDelete.txt");


    // begin = rdtsc();

    // while(times != 1000){
    head = delete_table;
    while(head){
        prefix_delete(&routing_table,head);
        head = head->next;
    }


    // end = rdtsc();
    // printf("%llu\n",(end-begin));
    // times++;
    // }

    // printf("The total number of prefixes in the input file is : %d.\n",Len(routing_table));
    // PrintLinkedList(routing_table);
    
    //DO SEARCH
    printf("Do search:\n");
    struct prefix *search_table = NULL;
    input(&search_table,argv[4]);
    // input(&delete_table,"C:\\Users\\a0987\\Desktop\\hw\\HW11\\testSearch.txt");



    while(times!= 10){
    begin = rdtsc();
    head = search_table;
    int result;
    while(head){
        result = search(routing_table,head);
        head = head->next;
        // printf("%s\n",result?"True":"False");
    }
    

	end = rdtsc();
    printf("%llu\n",(end-begin));
    }

    printf("The total number of prefixes in the input file is : %d.\n",Len(routing_table));
    // PrintLinkedList(routing_table);
    
// .\hw11 routing_table.txt inserted_prefixes.txt deleted_prefixes.txt trace_file.txt 8
// .\hw11 test.txt testInsert.txt testDelete.txt testSearch.txt 8 
	
}