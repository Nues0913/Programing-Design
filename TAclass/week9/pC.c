#include<stdio.h>

int ans[8],check[9];

void p(int i){
    if(i == 8){
        for(int j = 0;j<8;j++)
            printf("%d ",ans[j]);
        printf("\n");
        return;
    }
    for(int j = 1;j<=8;j++){
        if(check[j] == 0){
            ans[i] = j;
            check[j] = 1;
            p(i+1);
            check[j] = 0;
            

        }
    }
}

int main(){
    p(0);

    return 0;
} 