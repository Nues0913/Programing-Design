#include <stdio.h>
#include <string.h>

void areAnagrams(char str1[], char str2[]) {
    int size1=strlen(str1),size2=strlen(str2);
    if(size1 != size2){
        printf("No");
    } else {
        int same = 0;
        for(int i = 0;i < size1;i++){
            for (int j = 0; j < size2; j++){
                if(str1[i] == str2[j]){
                    same += 1;
                    str2[j] = 0;
                    break;
                }
            }
        }
        if (same == size1){
            printf("Yes");
        } else {
            printf("No");
        }
    }
}

int main() {
    char str1[100], str2[100];
    
    scanf("%s", str1);
    
    scanf("%s", str2);

    areAnagrams(str1, str2);
    

    return 0;
}