#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j;
  int n;
  scanf("%d", &n);

  // v 자
  for (i = 0; i < n; i++) {
    for (j = 0; j < i; j++) {
      printf(" ");
    }
    printf("*");
    for (j = 0; j < 2 * (n - i) - 2; j++) {
      printf(" ");
    }
    printf("*\n");
  }
  // 받침대 행 2i 열 i
  for (i = 0; i < n; i++) {
    printf("*");

    for (j = 0; j < (2 * n) - 2; j++) {
      printf("*");
    }
    printf("*\n");
  }
  // 역삼각형
  for (i = n; i >= 1; i--) {
    for (j = 0; j < n - i; j++) {
      printf(" ");
    }
    for (j = 2 * i; j >= 1; j--) {
      printf("*");
    }
    printf("\n");
  }

  // 마지막 행 2i
  for (i = 0; i < (2 * n) ; i++) {
    printf("*");
  }

  return EXIT_SUCCESS;
}
