#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define bool int
#define True 1
#define False 0

int main(){
    printf("%s %s %s %s %s %s %s %s","How","many","strings","are","you","going","to","enter? ");
    int num;

    // if you need detect wrong enter
    while((scanf("%d",&num)) != -1){
        char c;
        bool isCurrectStdin = True;
        while ((c = getchar()) != '\n' && c != EOF) isCurrectStdin = False;    // detect if extra string in stdin and clear buffer
        if (isCurrectStdin) break;
        printf("%s %s %s %s %s %s %s %s","How","many","strings","are","you","going","to","enter? ");
    }

    // if not just use this
    // scanf("%d",&num);

    // create twoD array to store str
    printf("%s %d %s","enter",num,"strings:\n");
    char **str = (char **)malloc(num*sizeof(char *));
    for(int i = 0;i<num;i++){
        char enter[50];
        gets(enter);    // avoid scanf if needs to scan space
        *(str+i) = (char *)malloc(sizeof(enter));
        strcpy(*(str+i),enter);
    }
    printf("\n");

    printf("%s %c %s %s %s %s","Enter",'a',"string","to","search","(EOF to end): ");
    char enter[50];
    while(gets(enter)){
        bool isFound = False;
        int i;
        for(i = 0;i<num;i++){
            if(strcmp(enter,*(str+i)) == 0){
                isFound = True;
                break;
            }
        }
        if(isFound){
            printf("%s %s %s %d %s %s %s %s\n\n","Found","in","row",i+1,"in","the","above","list.");
        } else {
            printf("%s %s\n\n","Not","found!");
        }
        printf("%s %c %s %s %s %s","Enter",'a',"string","to","search","(EOF to end): ");
    }
}