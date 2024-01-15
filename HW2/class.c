#include<stdio.h>
#include<math.h> 
int main()
{
    double n[6] = {3.0,3.1,3.14,3.141,3.1415,3.14159};
    double scope = 1.0;
    double sum ;
    double terms = 1.0;
    printf("Estimate pi = 4/1 - 4/3 + 4/5 - 4/7 + 4/9 - 4/11 + ...\n");
    for (int i = 0; i < 6; i++)
    {
        sum = 0.0;
        while (1)
        {
            if ((int)terms % 2 != 0)
            {
                sum = sum + 4.0/(2.0*terms-1);
                terms++;
                // printf("%f\n",sum);
            }
            else
            {
                sum = sum - 4.0/(2.0*terms-1);
                terms++;
                // printf("%f\n",sum);
            }
            if(sum - n[i] > 0 && sum - n[i] < scope){
                printf("Term = %10.0f ---> pi = %.15f\n",terms-1,sum);
                terms = 1.0;
                scope = scope*0.1;
                break;
            }
        }   
    }
    printf("hi");
}