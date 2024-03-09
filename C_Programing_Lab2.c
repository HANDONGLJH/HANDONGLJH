#include <stdio.h>
#include <stdlib.h>

int main() {
  int persons[4][3];
  int sum[3] = {0};
  float ratio[3];
  int i, j;
  int total = 48;

  // 점호 학생 수 (반복문을 이용하여 방의 호수마다 인원 배당+ 1,3층)
  for (i = 1; i <= 4; i++) {
    if (i == 1)
      printf("Check room (Men)\n");
    else if (i == 3)
      printf("check room (Women)\n");
    for (j = 1; j <= 3; j++) {

      printf("ROOM #%d0%d>: ", i, j);
      scanf("%d", &persons[i][j]);
      sum[0] += (i < 2) ? persons[i][j] : 0;  // 남학생수 총합
      sum[1] += (i >= 2) ? persons[i][j] : 0; // 여학생수 총합
      sum[2] += persons[i][j];                // 학생수 총합
    }
  }

  // 점호 비율 계산 및 출력
  ratio[0] = (float)sum[0] / total / 2;
  ratio[1] = (float)sum[1] / total / 2;
  ratio[2] = (float)sum[2] / total;

  printf("CHECK RESULT\n");
  printf("MEN: %d/%d (%.1f %%)\n", sum[0], total / 2, ratio[0]);
  printf("WOMAN: %d/%d (%.1f %%)\n", sum[1], total / 2, ratio[1]);
  printf("TOTAL: %d/%d (%.1f %%)\n", sum[2], total, ratio[2]);

  return EXIT_SUCCESS;
}
