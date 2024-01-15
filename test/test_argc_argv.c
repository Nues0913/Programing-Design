#include <stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]) {
  printf("We have %d arguments:\n", argc);
  for (int i = 0; i < argc; ++i) {
    // printf("[%d] %d\n", i, atoi(argv[i]));
    printf("[%d] %s\n", i, argv[i]);
  }
  return 0;
}