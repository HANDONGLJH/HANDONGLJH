/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
리턴값은 1~5이니 5로 나눠준값에 1을 더한 값이 나오는 변수를 설정한다.
do while문을 사용하여 각방에 두명이들어있을시 다른방을 찾게 설정했고

이를 위해 main함수에 남자층과 여자층에서 배열의 값을 업데이트하는 코드를
추가했다.

*/
int findRoom(int persons[5]) {
  int room;
  do {
    room = (rand() % 5) + 1;
  } while (persons[room - 1] >= 2);

  return room;
}

/*
패러미터들이 갖고있느 의미를 먼저 파악해보니
mn은 남학생들의 이름 , mr은 호실번호 , mc는 총 수 들의 배열이다.

반복문을 통하여 명단들을 출력하고 중첩문을 통하여 호실별 배정결과를 출력하면
될것이다.
  */
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20],
                 int wr[10], int wc) {
  printf("생활관 호실 배정은 다음과 같습니다. \n");
  printf("===================================\n");
  // 남자
  printf("남학생 명단: %d명 \n", mc);
  for (int i = 0; i < mc; i++) {
    printf("%d. %s [%d호]\n", i + 1, mn[i], mr[i]);
  }
  // 여자
  printf("\n여학생 명단: %d명 \n", wc);
  for (int i = 0; i < wc; i++) {
    printf("%d. %s [%d]\n", i + 1, wn[i], wr[i]);
  }
  // 호실별
  printf("\n호실별 배정 결과:\n");
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= 5; j++) {
      printf("%d0%d호: ", i, j);
      for (int k = 0; k < mc; k++) {
        if (mr[k] == i * 100 + j) {
          printf("%s, ", mn[k]);
        }
      }
      for (int k = 0; k < wc; k++) {
        if (wr[k] == i * 100 + j) {
          printf("%s, ", wn[k]);
        }
      }
      printf("\n");
    }
  }
}

int main() {
  char mnames[10][20];        // 남학생명단(최대 10명)
  int mroom[10];              // 남학생명단별 호실 배정 목록
  char wnames[10][20];        // 여학생명단(최대 10명)
  int wroom[10];              // 여학생명단별 호실 배정 목록
  int person[2][5] = {0};     // 2개 층별 5개 호실의 배정 인원 수
  int mcount = 0, wcount = 0; // 인원 합계 (남, 여)
  int menu;

  int error=0;

  srand(time(0));
  printf("===========================================\n");
  printf("생활관 호실 배정 프로그램\n");
  printf("===========================================\n");
  
  while (1) {
    if (mcount + wcount >= 10) {
      if (!error) {
        printf("정원 초과입니다. 등록불가!\n");
        error = 1;
      }
      break; // 에러처리
    }
    printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
    scanf("%d", &menu);
    if (menu == 0)
      break;
    else if (menu == 1) {
      printf("학생 이름은? > ");
      scanf("%s", mnames[mcount]);
      int roomno = findRoom(person[0]);
      mroom[mcount] = 100 + roomno;
      printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
      //업데이트
      person[0][roomno - 1]++;
      mcount++;
    } else if (menu == 2) {
      printf("학생 이름은? > ");
      scanf("%s", wnames[wcount]);
      int roomno = findRoom(person[1]);
      wroom[wcount] = 200 + roomno;
      printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
      // 업데이트 
      person[1][roomno - 1]++;
      wcount++;
    }
  }
  printf("===========================================\n");
  printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
  printf("===========================================\n");
  printReport(mnames, mroom, mcount, wnames, wroom, wcount);
  return 0;
  }
