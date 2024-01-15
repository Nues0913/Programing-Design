#include <stdio.h>
#include <stdlib.h>
#include "hw8-2.h"

void modify(int* a, int n) {
    *a = n+1;
}

int query(int (*mp)[131][131][131], char a[4], char b[4]) {
    int n1 = (int)a[0];
    int n2 = (int)a[1];
    int n3 = (int)a[2];
    int n4 = (int)b[0];
    int n5 = (int)b[1];
    int n6 = (int)b[2];
    int flight1 = (*mp)[n1][n2][n3];
    int flight2 = (*mp)[n4][n5][n6];
    int sum =  flight1 + flight2;

    if (sum % 2 != 0) {
        return 1;
    } else {
        return 0;
    }
}
