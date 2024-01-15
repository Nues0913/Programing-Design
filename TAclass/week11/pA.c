#include <stdio.h>

void swap(int *pa,int *pb ){
    int tem = *pa;
    *pa = *pb;
    *pb = tem;

}

int main() {
    int a,b;
    
    scanf("%d %d", &a, &b);
    
    printf("before:\n");
    printf("%d %d\n", a, b);
    
    swap(&a,&b);
    
    printf("after:\n");
    printf("%d %d\n", a, b);
}