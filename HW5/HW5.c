#include<stdio.h>
int gcd(int, int, int);
int main(){
    printf("//////////Welcome to NCKU-PD1-Kirby-Shop\\\\\\\\\\\\\\\\\\\\\n");
    int option = 0;
    int opened = 0;
    int temx = -2;
    int temy = -2;
    int temz = -2;
    int tembox = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    int kirby = 0;
    int money = 0;
    int check = 0;
    while (option != 4)
    {   
        printf("Options: (1)Openning (2)List (3)Adding (4)Exit\n");
        scanf("%d",&option);
        // printf("%d",option);
        if(option != 1 && option != 2 && option !=3 && option != 4){
            printf("Error: Please try again!\n");
            char c;
            while (  (c = getchar()) != '\n' && c != EOF);
            option = 0;
            continue;;
        }
        switch (option)
        {
        case 1:     //Opening
            if(opened == 0){
                printf("Your shop is openning!\n");
                opened = 1;
                option = 0;
            } else {
                printf("Your Kirby shop has already opened :(\n");
                char c;
                while (  (c = getchar()) != '\n' && c != EOF);
                option = 0;
            }
            continue;

        case 2:     //List
            printf("===================================\n");
            printf("Kirby-A: %d\n",x);
            printf("Kirby-B: %d\n",y);
            printf("Kirby-C: %d\n",z);
            printf("Kirby: %d, Money: %d\n",kirby,money);
            printf("===================================\n");
            option = 0;
            continue;

        case 3:     //Adding
            if(opened == 1){
                printf("Please enter three numbers: ");
                check = 0;
                scanf("%d%d%d",&temx,&temy,&temz);
                char check2;
                // printf("%d%d%d %c\ncheck=%d\n",temx,temy,temz,check2,check);
                while (((check2 = getchar()) != '\n' && check2 != EOF)  || (((temx <= 0 || temy <= 0 || temz <= 0) && (temx != -1 || temy != -1 || temz != -1))) || (temx == -1 && temy == -1 && temz == -1 && check == 0)){   
                    check = 1;
                    // printf("%d%d%d %c\ncheck=%d\n",temx,temy,temz,check2,check);
                    printf("Error: Please try again or enter '-1 -1 -1' to make a new options: ");
                    if(check2 != '\n'){
                        char c;
                        while (  (c = getchar()) != '\n' && c != EOF);
                    }
                    scanf("%d%d%d",&temx,&temy,&temz);
                }
                if(temx == -1 && temx == -1 && temz == -1){
                    continue;
                }
                tembox = gcd(temx,temy,temz);
                printf("Divide these Kirbys into %d boxes, with the number of Kirby in each box being %d, %d, and %d\n",tembox,temx/tembox,temy/tembox,temz/tembox);
                printf("Price: %d\n",(temx+temy+temz)-tembox*2);
                // printf("%d%d%d\n",temx,temy,temz);
                x += temx;
                y += temy;
                z += temz;
                kirby += temx+temy+temz;
                money += (temx+temy+temz)-tembox*2;
                option = 0;
                temx = 0;
                temy = 0;
                temz = 0;
            } else {
                printf("Your Kirby shop has not opened\n");
                option = 0;
            }
            continue;

        case 4:     //Exit  
            break;
        }
        
    }
    
    return 0;
}

int gcd(int x, int y, int z){
    int tem;
    if(x<y){
        tem = x;
        x = y;
        y = tem;
    }
    if(y<z){
        tem = y;
        y = z;
        z = tem;
    }
    if(x<y){
        tem = x;
        x = y;
        y = tem;
    }
    int t = 1;
    while (t != 0){
        t = x%y;
        x = y;
        y = t;
    }
    y = x;
    t = 1;
    if(y<z){
        tem = y;
        y = z;
        z = tem;
    }
    while (t != 0)
    {
        t = y%z;
        y = z;
        z = t;
    }

    return y;
}