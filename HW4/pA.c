#include <stdio.h>
int main()
{
    int days,starting_day;
    printf("Enter number of days in month: ");
    scanf("%d",&days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d",&starting_day);
    for(int i = 0;i<1 + (starting_day-1)*3;i++)
        printf(" ");
    for(int i = 1;i<=days;i++){
        if(i < 10)
            printf(" ");
        printf("%d",i);
        if((i+starting_day-1)%7 == 0)
            printf("\n");
        if(i != days)
            printf(" ");
    }
  return 0;
}