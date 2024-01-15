#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *file = fopen("text.txt", "r");

// char line[256]; 
//     while (fgets(line, sizeof(line), file) != NULL) {
//         printf("%s", line);
//     }

int num1, num2, num3, num4, num5;
//讀取到變數中
while (fscanf(file, "%d.%d.%d.%d/%d", &num1, &num2, &num3, &num4, &num5) == 5) {
    printf("Read: %d.%d.%d.%d/%d\n", num1, num2, num3, num4, num5);
}
}