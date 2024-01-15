#include <stdio.h>
int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    if(((a>0 && b<0) || (a<0 && b>0)) || a == 0 || b == 0){
        printf("No");
    }else if(a > 0 && b > 0 && 9223372036854775807-a >= b){
        printf("No");
    }else if(a < 0 && b < 0 && -9223372036854775807-a-1 <= b){
        printf("No");
    }else{
        printf("Yes");
    }
    return 0;
}
