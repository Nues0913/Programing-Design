#include<stdio.h>
#include<string.h>
int main(){

    FILE *file = fopen("example.txt", "r");
    // 逐行讀取
    char line[256]; 
    char **lines;
    
    int i = 0;
        while (fgets(line, sizeof(line), file) != NULL) {
            memcpy(*(lines+i), line, sizeof(line));
            printf("%s", line);
            i++;
        }
        
    // int num1, num2;
    // //讀取到變數中
    // while (fscanf(file, "%d %d", &num1, &num2) == 2) {
    //     printf("Read: %d %d\n", num1, num2);
    // }
}