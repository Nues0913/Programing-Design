#include<stdio.h>
long long arra[200000] = {0};

int Homework6_1(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
        scanf("%lld",&arra[i]);
    for(int i = n-1;i>=0;i--){
        printf("%lld",arra[i]);
        if(i != 0){
            printf(" ");
        }
    }
    return 0;
}

int Homework6_2(){
    int n;
    int temp;
    scanf("%d",&n);
    for(int i = 0;i<n-1;i++){
        scanf("%d",&temp);
        arra[temp] = 1;
    }
    for(int i = 1;i<=n;i++){
        if(arra[i] == 0){
            printf("%d",i);
            break;
        }
    }
}

int Homework6_3(){
    long long n,q;
    long long sum[100000] = {0};
    long long ans[100000] = {0};
    scanf("%lld",&n);
    for(long long i = 1;i<=n;i++){
        scanf("%lld",&arra[i]);
        sum[i] = sum[i-1] + arra[i];
    }
    scanf("%lld",&q);
    for(long long i = 0;i<q;i++){
        long long L,R;
        scanf("%lld %lld",&L,&R);
        ans[i] = sum[R] - sum[L-1];
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
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            scanf("%d",&twoDarra[i][j]);
        }
    }
    for(int i =0;i<5;i++){
        int a[2],b[2],temp;
        scanf("%d %d %d %d",&a[0],&a[1],&b[0],&b[1]);
        temp = twoDarra[a[0]-1][a[1]-1];
        twoDarra[a[0]-1][a[1]-1] = twoDarra[b[0]-1][b[1]-1];
        twoDarra[b[0]-1][b[1]-1] = temp;
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

    case 2:
        Homework6_2();

    case 3:
        Homework6_3();

    case 4:
        Homework6_4();

    }

    return 0;
}
