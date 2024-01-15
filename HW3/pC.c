#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d-%d-%d",&a,&b,&c);
    int total = 0;
    if (a==b && a==c && b==c){
        total += 300;
    }
    if(a+b<c){
        total += 150;
    }
    if(a==c){
        total += 100;
    }
    if(a<b){
        total += 50;
    }
    printf("%d",total);

}