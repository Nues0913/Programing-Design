#include <stdio.h>
#include <stdlib.h>
#include "hw8-1.h"

void init(int*** mp){
    for(int i = 0;i<130;i++){
        mp[i] = (int**)malloc( 130*sizeof(int*));
        for(int j = 0;j<130;j++){
            mp[i][j] = (int*)malloc( 130*sizeof(int));
            for(int k = 0;k<130;k++){
                mp[i][j][k] = 1;
            }
        }
    }
}

void modify(int* a, int n) {
    *a = n;
}


int query(int**** mp, char a[4], char b[4]) {
    int n1 = a[0];
    int n2 = a[1];
    int n3 = a[2];
    int n4 = b[0];
    int n5 = b[1];
    int n6 = b[2];

    int sum = (*mp)[n1][n2][n3] + (*mp)[n4][n5][n6];
    
    if (sum % 2 != 0){
        return 1;
    } else {
        return 0;
    }
}



