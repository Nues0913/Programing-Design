#include<stdio.h>
int main(){
    int a = 1234;
    int *a_pointer = &a;

    printf("%d\n", a);
    // 1234
    // 00000000 00000000 00000100 11010010
    *((unsigned char*)a_pointer) = 123;
    // 123 == 01111011
    // 00000000 00000000 00000100 01111011
    printf("%d\n", a);
    // 1147
}