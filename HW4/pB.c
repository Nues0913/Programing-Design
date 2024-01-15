#include<stdio.h>
int main(){
    double e = 1.0;
    int n;
    double tem;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        tem = 1;
        for(int j = 1;j<=i;j++){
            tem *= 1/j;
        }
        e += tem;
    }
    printf("%f",e);
    return 0;
}