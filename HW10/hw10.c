#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef double (*F)(double,int);

double power(double x, int n){
    if(n<0)  return power((double)(1/x),-n);
    if(n == 0) return 1.0;
    if(n == 1) return x;
    return (double)x*power(x,n-1);
}

double multiply(double x, int n){
    return (double)x*n;
}

double divide(double x, int n){
    return (double)x/n;
}

double powerpower(F func,double x,int n,int m){
    double result = func(x,n);
    if(m < 0) return powerpower(func, (double)(1/x), n, -m);
    if(m == 0) return 1.0;
    for(int i = 1;i<m;i++){
        result *= func(x,n);
    }
    return result;

}

int main(int argc, char *argv[]){
    printf("-------- powerpower(power,x,n,m) --------\n");
    printf("%lf\n",powerpower(power,atof(argv[1]),atoi(argv[2]),atoi(argv[3])));
    printf("-------- powerpower(multiply,x,n,m) --------\n");
    printf("%lf\n",powerpower(multiply,atof(argv[1]),atoi(argv[2]),atoi(argv[3])));
    printf("-------- powerpower(divide,x,n,m) --------\n");
    printf("%lf\n",powerpower(divide,atof(argv[1]),atoi(argv[2]),atoi(argv[3])));
}