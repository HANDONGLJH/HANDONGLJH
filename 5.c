// 21600540 이재호

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 50

char LNAME[5][30] = {"Graphite", "Opal", "Bronze", "Silver",
                     "Gold"}; // labels by level

struct st_channel {
  char name[100]; // Channel name
  int count;      // # of subscriptions
  int level;      // index of level (0~4)
};

int loadData(struct st_channel *c[]);
int findLevel(int num);
void printStatistics(struct st_channel *c[], int size);
void printChannels(struct st_channel *c[], int size);
void pickupRandomChannels(struct st_channel *c[], int size);
void searchChannel(struct st_channel *c[], int size);
int addChannel(struct st_channel *c[], int size);
void updateChannel(struct st_channel *c[], int size);
int deleteChannel(struct st_channel *c[], int size);
void makeReport(struct st_channel *c[], int size);

int main(void) {
  int no;                         // amount of channels
  struct st_channel *clist[SIZE]; // channel list
  int menu;                       // menu number

  srand(time(0));
  no = loadData(clist);

  while (1) {
    // Print menu
    printf("\n[1]List [2]Statistics [3]Random pick [4]Search [5]Add [6]Modify "
           "[7]Delete [8]Report [0]Exit\n> Enter a menu >> ");
    scanf("%d", &menu);

    if (menu == 1) {
      printChannels(clist, no); // Print all list of channels
    } else if (menu == 2) {
      printStatistics(clist, no); // Print statistics of each level
    } else if (menu == 3) {
      pickupRandomChannels(clist, no); // Pick up random channels
    } else if (menu == 4) {
      searchChannel(clist, no); // Search a channel
    } else if (menu == 5) {
      no = addChannel(clist, no); // Add a channel
    } else if (menu == 6) {
      updateChannel(clist, no); // Modify a channel
    } else if (menu == 7) {
      no = deleteChannel(clist, no); // Delete a channel
    } else if (menu == 8) {
      makeReport(clist, no); // Make a Report
    } else {
      break;
    }
  }
  return 0;
}

int loadData(struct st_channel *c[]) {
  int no = 0;
  FILE *file;

  file = fopen("channels.txt", "r");
  while (!feof(file)) {
    struct st_channel *t =
        (struct st_channel *)malloc(sizeof(struct st_channel));
    int r = fscanf(file, "%s %d", t->name, &(t->count));
    if (r < 2)
      break;
    t->level = findLevel(t->count);
    c[no] = t;
    no++;
  }
  fclose(file);
  printf("> %d channels are loaded.\n", no);
  return no;
}

int findLevel(int num) {
  int range[5] = {1000, 10000, 100000, 1000000, 10000000}; // range for level
  for (int j = 0; j < 5; j++)
    if (num < range[j])
      return j;
  return 0;
}

void printChannels(struct st_channel *c[], int size) {
  printf("> List of Channels\n");
  for (int i = 0; i < size; i++) {
    printf("[%2d] %-20s %10d peoples [%s] \n", i + 1, c[i]->name, c[i]->count,
           LNAME[c[i]->level]);
  }
}

int addChannel(struct st_channel *c[], int size) {
  struct st_channel *temp;
  printf("> Add a new Channel\n");
  temp = (struct st_channel *)malloc(sizeof(struct st_channel));
  printf("> Enter a name of channel > ");
  scanf("%s", temp->name);
  printf("> Enter an amount of peoples > ");
  scanf("%d", &(temp->count));
  temp->level = findLevel(temp->count);
  c[size] = temp;
  printf("> New channel is added.\n");
  printf("[%2d] %-20s %10d peoples [%s] \n", size + 1, c[size]->name,
         c[size]->count, LNAME[c[size]->level]);
  return size + 1;
}
////////////////////////////////////////////////

// 채널 목록에서 다양한 통계 정보를 계산하고 출력하는 역할, 초기화 통계수집 출력
// 최대 구독자 수 출력
void printStatistics(struct st_channel *c[], int size) {
  int levelCounts[5] = {0}, maxSubs = 0, totalSubs[5] = {0};
  // 각 레벨의 채널 수와 전체 구독자 수를 저장할 배열 초기화
  struct st_channel *maxChannel = NULL;
  // 가장 구독자 수가 많은 채널을 저장할 포인터
  // 통계 정보 수집
  for (int i = 0; i < size; i++) {
    int lvl = c[i]->level;
    levelCounts[lvl]++;
    totalSubs[lvl] += c[i]->count;
    //가장 구독자 수가 많은  채널 업데이트
    if (!maxChannel || c[i]->count > maxChannel->count)
      maxChannel = c[i];
  }
  // 통계 출력
  printf("\nStatistics:\n");
  for (int i = 0; i < 5; i++) {
    printf("%s: %d Channels, Average subscribers: %.2f\n", LNAME[i],
           levelCounts[i],
           levelCounts[i] ? (double)totalSubs[i] / levelCounts[i] : 0.0);
  }
  // 가장 구독자 수가 많은 채널 출력
  if (maxChannel) {
    printf("Channel with most subscribers: %s (%d subscribers)\n\n",
           maxChannel->name, maxChannel->count);
  }
}

//  사용자가 지정한 수만큼 채널 목록에서 무작위로 채널을 선택하여 정보를
//  출력하는 역할 ,사용자 입력 수집+랜덤 채널 선택 및 출력
void pickupRandomChannels(struct st_channel *c[], int size) {
  int num; // 랜덤하게 선택할 채널의 수
  printf("Number of channels to pick: ");
  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    int idx = rand() % size; // 랜덤한 채널 인덱스
    // 선택된 채널 정보를 출력
    printf("%s with %d subscribers [%s level]\n", c[idx]->name, c[idx]->count,
           LNAME[c[idx]->level]);
  }
}

// 채널 목록에서 특정 기준에 따라 채널을 검색하고, 일치하는 채널의 정보를
// 출력하는 역할, 검색 옵션을 먼저 선택하고, 구독자 수 범위로 검색, 채널 이름에
// 특정 문자열을 검색할 수 있어야한다.
void searchChannel(struct st_channel *c[], int size) {
  int choice;
  printf("1. Search by subscriber range\n2. Search by channel name containing "
         "string\n> ");
  scanf("%d", &choice);
  if (choice == 1) {
    int min, max;
    printf("Enter minimum and maximum subscriber count: ");
    scanf("%d %d", &min, &max);
    for (int i = 0; i < size; i++) {
      if (c[i]->count >= min && c[i]->count <= max) {
        printf("%s with %d subscribers [%s level]\n", c[i]->name, c[i]->count,
               LNAME[c[i]->level]);
      }
    }
  } else if (choice == 2) {
    char input[100];
    printf("Enter string to search in channel name: ");
    scanf("%s", input);
    for (int i = 0; i < size; i++) {
      if (strstr(c[i]->name, input)) {
        printf("%s with %d subscribers [%s level]\n", c[i]->name, c[i]->count,
               LNAME[c[i]->level]);
      }
    }
  }
}

//사용자가 선택한 채널의 정보(이름과 구독자 수)를 수정하고 업데이트하는 기능을
//수행, 채널 번호를 우선 입력 받고, 채널 번호가 유효한 범위 내에 있는지
//체크하고, 새로운 채널 정보를 입력받은 후 업데이트 하는 함수

void updateChannel(struct st_channel *c[], int size) {
  int num;
  printf("Channel number to modify: ");
  scanf("%d", &num);

  if (num - 1 >= 0 && num - 1 < size) {
    printf("Enter new name: ");
    scanf("%s", c[num - 1]->name);
    printf("Enter new subscriber count: ");
    scanf("%d", &c[num - 1]->count);
    c[num - 1]->level = findLevel(c[num - 1]->count);
    printf("Channel #%d updated.\n", num);
  } else {
    printf("Invalid channel number.\n");
  }
}

// 사용자가 선택한 채널을 목록에서 완전히 삭제하는 기능을 수행, 삭제할 채널
// 번호를 입력 받고 , 그 번호가 목록범위 내에 있는지 확인하고 입력받은 번호에
// 해당하는 채널을 메모리에서 해제해준다 그 후 채널을 하나씩 앞으로 당겨주고
// 최신화된 채널 목록의 크기를 반환한다.

int deleteChannel(struct st_channel *c[], int size) {
  int num;
  printf("Enter channel number to delete: ");
  scanf("%d", &num);
  num--;
  if (num >= 0 && num < size) {
    free(c[num]);
    for (int i = num; i < size - 1; i++) {
      c[i] = c[i + 1];
    }
    printf("Channel deleted.\n");
    return size - 1;
  } else {
    printf("Invalid channel number.\n");
    return size;
  }
}

//  채널 목록과 통계 정보를 파일에 기록하여 보고서를 생성하는 작업을 수행 ,
//  파일을 쓰기 모드로 열고 report텍스트파일로 변경하여 저장 .그후 채널 목록과
//  통계 정보를 출력하고 , 표준출력 복구 후 채널 목록을 업데이트해준다.

void makeReport(struct st_channel *c[], int size) {
  // `report.txt` 파일을 쓰기 모드로 열기
  FILE *report = fopen("report.txt", "w");
  if (report != NULL) {
    // stdout을 `report.txt`에 대한 파일 스트림으로 변경
    FILE *originalStdout = stdout;
    stdout = report;

    // 출력 함수 재실행하여 파일로 리디렉션
    printChannels(c, size);
    printStatistics(c, size);

    // stdout을 원래대로 복구
    stdout = originalStdout;

    fclose(report);
    printf("Report generated.\n");
  } else {
    printf("Failed to open report.txt for writing.\n");
  }

  // 'channels.txt' 파일을 업데이트
  FILE *channelsFile = fopen("channels.txt", "w");
  if (channelsFile != NULL) {
    for (int i = 0; i < size; i++) {
      fprintf(channelsFile, "%s %d\n", c[i]->name, c[i]->count);
    }
    fclose(channelsFile);
    printf("Channels list updated.\n");
  } else {
    printf("Failed to open channels.txt for writing.\n");
  }
}
