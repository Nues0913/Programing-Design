#include <stdio.h>

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void printAllSums(int k, int currentSum, int startIndex, int combination[], int combinationSize) {
    if (k == 0) {
        // printf("%d ", currentSum);

        if(currentSum == 15){
            for (int i = 0; i < combinationSize; i++) {
                printf("%d ", combination[i]);
            }
            printf("\n");
        }

        return;
    }

    for (int i = startIndex; i < 10; i++) {
        combination[combinationSize] = arr[i];
        printAllSums(k - 1, currentSum + arr[i], i + 1, combination, combinationSize + 1);
    }
}

int main() {
    int k = 3;
    int combination[k];
    printAllSums(k, 0, 0, combination, 0);

    return 0;
}
