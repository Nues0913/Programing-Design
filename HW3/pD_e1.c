#include <stdio.h>
int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    if((a ^ b) < 0 || ((a + b) ^ a) >= 0){  //a^b < 0 ��Ӥ��P�� || (a+b)^a ��ӦP���ɡAa+b�Pa���P��
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