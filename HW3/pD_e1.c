#include <stdio.h>
int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    if((a ^ b) < 0 || ((a + b) ^ a) >= 0){  //a^b < 0 兩個不同號 || (a+b)^a 兩個同號時，a+b與a不同號
        // printf("%d\n",a^b);
        // printf("%d\n",(a+b)^a);
        printf("No");
    }else{
        // printf("%d\n",a^b);
        // printf("%d\n",(a+b)^a);
        printf("yes");
    }
    return 0;
}