#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Using rand() to generate a random number between 1 and 6.
int rollDice(int i) {
    srand(i);
    int x = rand()%6+1;
    return x;
}

int main() {
    
    int totalRolls = 10000; // you could modify the totalRolls
    double expectedValue = 0.0;
    for(int i = 1;i<=totalRolls;i++)
        expectedValue += rollDice(i+time(NULL));
    expectedValue /= totalRolls;
    printf("%f\n",expectedValue);
    printf("The Expected Value is %lf\n", expectedValue);

    return 0;
}