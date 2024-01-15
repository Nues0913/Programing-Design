#include<stdio.h>
int z(int x){
    return 2023 - 5*x;
}
int y(int x){
    return 6*x+10;
}
int f(int x){
    return y(z(x)) +7*x;
}
int main(){
    int x;
    scanf("%d",&x);
    printf("%d",f(x));
    return 0;
}