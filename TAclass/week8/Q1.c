#include <stdio.h>

void decimalToBinary(int num) {   
    if (num == 0) {
        printf("0");
        return;
    }
    if (num == 1) {
        printf("1");
        return;
    }
    int binary[100];
    int tem = 0;
    int i = 0;
    while(num > 0){
        binary[i] = num % 2;
        num = num / 2;
        i ++;
    }
    for(int j = i-1;j >= 0;j--){
        printf("%d",binary[j]);
    }
    // 1 2   3   4   5   6   7   8     9   10
    // 1 10 11 100 101 110 111 1000 1001 1010
}

int main() {
    int num;
    
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    decimalToBinary(num);

    return 0;
}