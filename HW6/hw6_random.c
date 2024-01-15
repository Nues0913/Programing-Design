#include<stdio.h>
#include<stdlib.h>
#include<time.h>
long long arra[200000] = {0};

int Homework6_1(){
    int n=0;
    srand(time(NULL));
    // scanf("%d",&n);
    n = rand()%200000+1;
    while(n < 5000){
        n *= 2;
    }
    // n = 5001;
    printf("%d\n",n);
    for(int i = 0;i<n;i++)
        // scanf("%lld",&arra[i]);
        arra[i] = rand()%1000000000+1;

    for(int i = 0;i<n;i++){
        printf("%lld",arra[i]);
        if(i != n-1){
            printf(" ");
        }
    }
    printf("\n");
    for(int i = n-1;i>=0;i--){
        printf("%lld",arra[i]);
        if(i != 0){
            printf(" ");
        }
    }
    return 0;
}

int Homework6_2(){
    int n=0;
    int ans=0;
    srand(time(NULL));
    n = rand()%200000+1;
    while(n < 5000){
        n *= 2;
    }
    // n = 5001;
    while (ans == 0 || ans > n){
        ans = rand()%n+1;
    }
    // int temp;
    // scanf("%d",&n);
    // for(int i = 0;i<n-1;i++){
    //     scanf("%d",&temp);
    //     arra[temp] = 1;
    // }
    // for(int i = 1;i<=n;i++){
    //     if(arra[i] == 0){
    //         printf("%d",i);
    //         break;
    //     }
    // }
    printf("%d\n",n);
    for(int i = 1;i<=n;i++){
        if(i != ans){
            printf("%d",i);
        }
        if(i != n && i != ans){
            printf(" ");
        }
    }
    printf("\n%d",ans);
}

int Homework6_3(){
    long long n = 0;
    long long q = 0;
    long long sum[100000] = {0};
    long long ans[100000] = {0};
    // scanf("%lld",&n);
    srand(time(NULL));
    n = rand()%100000+1;
    while(n < 50000){
    n *= 2;
    }
    // n = 50000;
    printf("%lld\n",n);
    for(long long i = 1;i<=n;i++){
        // scanf("%lld",&arra[i]);
        arra[i] = rand()%1000000000+1;
        printf("%lld",arra[i]);
        if(i != n)
            printf(" ");
        sum[i] = sum[i-1] + arra[i];
    }
    printf("\n");
    // scanf("%lld",&q)3;
    q = rand()%100000+1;
    while(q < 50000){
        q *= 2;
    }
    // q = 50;
    printf("%lld\n",q);
    for(long long i = 0;i<q;i++){
        long long R = 0;
        long long L = 0;
        // scanf("%lld %lld",&L,&R);
        R = rand()%n+1;
        L = rand()%R+1;
        printf("%lld ",L);
        printf("%lld",R);
        ans[i] = sum[R] - sum[L-1];
        printf("\n");
    }
    for(long long i = 0;i<q;i++){
        printf("%lld",ans[i]);
        if( i != q-1){
            printf("\n");
        }
    }

}

int Homework6_4(){
    int twoDarra[1000][1000] = {0}; //it's too big to run at local,but AC in hw server
    int n=0;
    int m=0;
    // scanf("%d %d",&n,&m);
    srand(time(NULL));
    n = rand()%1000+1;
    while(n < 500){
        n *= 2;
    }
    m = rand()%1000+1;
    while(m < 500){
        m *= 2;
    }
    printf("%d %d\n",n,m);
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            // scanf("%d",&twoDarra[i][j]);
            twoDarra[i][j] = rand()%1000+1;
            printf("%d",twoDarra[i][j]);
            if(j != m-1)
                printf(" ");
        }
        printf("\n");
    }
    for(int i =0;i<5;i++){
        int a[2],b[2],temp;
        // scanf("%d %d %d %d",&a[0],&a[1],&b[0],&b[1]);
        a[0] = rand()%n;
        a[1] = rand()%m;
        b[0] = rand()%n;
        b[1] = rand()%m;
        temp = twoDarra[a[0]-1][a[1]-1];
        twoDarra[a[0]-1][a[1]-1] = twoDarra[b[0]-1][b[1]-1];
        twoDarra[b[0]-1][b[1]-1] = temp;
        printf("%d %d %d %d",a[0],a[1],b[0],b[1]);
        printf("\n");
    }
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            printf("%d",twoDarra[i][j]);
            if(j+1 != m)
                printf(" ");
        }
        if(i+1 != n)
            printf("\n");
    }
}
int main(){
    int opt;
    scanf("%d",&opt);
    switch (opt){
    case 1:
        Homework6_1();
        break;
    case 2:
        Homework6_2();
        break;
    case 3:
        Homework6_3();
        break;
    case 4:
        Homework6_4();
        break;
    }

    return 0;
}
