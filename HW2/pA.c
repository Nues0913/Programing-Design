#include<stdio.h>
int main(){
    int a,b,c,d;
    scanf("%d/%d+%d/%d",&a,&b,&c,&d);
    int e,f;
    f = b*d;
    e = a*d+b*c;
    printf("%d/%d\n",e,f);
    return 0;
}