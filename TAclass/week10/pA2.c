#include <stdio.h>
#include <string.h>
void areAnagrams(char str1[], char str2[]) {
    int count[124] = {0};
    if (strlen(str1) != strlen(str2)){
        printf("No");
        return;
    }
    int same = 0;
    for(int i = 0;i < strlen(str1);i++) count[str1[i]] += 1;
    for(int i = 0;i < strlen(str2);i++){
         if (count[str2[i]] != 0){
            same += 1;
            count[str2[i]]--;
        }
    }
    if(same == strlen(str1)){
        printf("Yes");
    } else {
        printf("No");
    }
}
int main() {
    char str1[100], str2[100];
    scanf("%s", str1);
    scanf("%s", str2);
    areAnagrams(str1, str2);
    return 0;
}