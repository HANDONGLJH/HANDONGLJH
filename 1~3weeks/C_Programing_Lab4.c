#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct st_class {
  int code;      // class code
  char name[30]; // class name
  int unit;      // credits
  int grading;   // grading (1:A+~F, 2:P/F)
};

char kname[2][10] = {"A+~F", "P/F"}; // String for grading

// 데이터 로드 함수

int loadData(struct st_class *c[]) {
  int count = 0;
  FILE *file;

  file = fopen("classes.txt", "r");
  while (!feof(file)) {
    c[count] = (struct st_class *)malloc(sizeof(struct st_class));
    int r = fscanf(file, "%d %s %d %d", &(c[count]->code), c[count]->name,
                   &(c[count]->unit), &(c[count]->grading));
    if (r < 4)
      break;
    count++;
  }
  fclose(file);
  return count;
}

// 모든 과목 출력 함수
void printAllClasses(struct st_class *c[], int csize) {
  for (int i = 0; i < csize; i++) {
    printf("[%d] %s [credit %d - %s]\n", c[i]->code, c[i]->name, c[i]->unit,
           kname[c[i]->grading - 1]);
  }
}

// 7 ok
void saveAllClasses(struct st_class *c[], int csize) {
  FILE *file;
  file = fopen("classes.txt", "w");
  for (int i = 0; i < csize; i++) {
    fprintf(file, "%d %s %d %d\n", c[i]->code, c[i]->name, c[i]->unit,
            c[i]->grading);
  }
  fclose(file);
}

// 4  ok
void findClasses(char *name, struct st_class *c[], int csize) {
  int count = 0;
  printf("Searching (keyword: %s)\n", name);
  for (int i = 0; i < csize; i++) {
    if (strstr(c[i]->name, name)) {
      printf("[%d] %s [credit %d - %s]\n", c[i]->code, c[i]->name, c[i]->unit,
             kname[c[i]->grading - 1]);
      count++;
    }
  }
  printf("%d classes found.\n", count);
}

/////////////////////////////////////////////////////////////////////////////////
///여기서부터 본래 코드와 다른점

/* 2
  메모리 할당후 과목 코드 입력 요청한다음
  중첩문을 통해  중복 코드를 확인하면 된다.
  이때 이미 존재하는 코드라면 변경없이 과목수를 리턴해주면된다.
  아니라면 새로운 과목을 배열에 추가후 / csize+1을 리턴해준다.

  */
int addNewClass(struct st_class *c[], int csize) {
  struct st_class *p =
      (struct st_class *)malloc(sizeof(struct st_class)); //메모리할당

  printf(">> code number > ");
  scanf("%d", &(p->code));

  for (int i = 0; i < csize; i++) {
    if (c[i]->code == p->code) { // 이미 존재시 처리
      printf("Class with this code already exists. Cannot add.\n");
      return csize;
    }
  }

  printf(">> class name > ");
  scanf("%s", p->name);
  printf(">> credits > ");
  scanf("%d", &(p->unit));
  printf(">> grading (1: A+~F, 2: P/F) > ");
  scanf("%d", &(p->grading));

  c[csize] = p; // 배열에 추가
  return csize + 1;
}

/*3 과목 수정함수에서 과목을 찾았을 때 현재과목 정보를 출력하고 , 수정된
  과목정보를 입력 받아야한다. 못 찾을 시 메세지를 출력한다.

  */
void editClass(struct st_class *c[], int csize) {
  struct st_class *p;
  int code;
  printf(">> Enter a code of class > ");
  scanf("%d", &code);

  /////////////
  int found = 0;
  for (int i = 0; i < csize; i++) {
    if (c[i]->code == code) {
      found = 1;
      printf("> Current: [%d] %s [credits %d - %s]\n", c[i]->code, c[i]->name,
             c[i]->unit, kname[c[i]->grading - 1]);
      printf("> Enter new class name > ");
      scanf("%s", c[i]->name);
      printf("> Enter new credits > ");
      scanf("%d", &(c[i]->unit));
      printf("> Enter new grading(1: Grade, 2: P/F) > ");
      scanf("%d", &(c[i]->grading));
      printf("> Modified.\n");
      break;
    }
  }

  if (!found) {
    printf("Class with code %d not found. Cannot edit.\n", code);
  }
}

/* 5 수강 신청함수는  일단 0입력시에 종료가 되어야한다.
  과목 존재여부에 따라 있을 시에 과목 코드로 찾아야하고
  내 수강 과목에 추가하고, 수강 과목 수가 증가되어야한다.

  그 후에 업데이트된 수강 과목수를 리턴받으면 된다.

  */
int applyMyClasses(int my[], int msize, struct st_class *c[], int csize) {
  int code;
  printf("Enter the class code to apply (0 to finish): ");

  while (1) {
    scanf("%d", &code);
    if (code == 0) {
      break;
    }

    int exists = 0;
    for (int i = 0; i < csize; i++) {
      if (c[i]->code == code) {
        exists = 1;
        my[msize] = code;
        msize++;
        printf("Class %s applied.\n", c[i]->name);
        break;
      }
    }

    if (!exists) {
      printf("Class with code %d does not exist. Cannot apply.\n", code);
    }
  }

  return msize;
}

/*6 수강 과목 출력함수는 중첩문을 통해
  코드로 과목을 찾고 , 정보를 출력한다.
  */
void printMyClasses(int my[], int msize, struct st_class *c[], int csize) {
  printf("My classes:\n");
  for (int i = 0; i < msize; i++) {
    for (int j = 0; j < csize; j++) {
      if (my[i] == c[j]->code) {
        printf("[%d] %s [credit %d - %s]\n", c[j]->code, c[j]->name, c[j]->unit,
               kname[c[j]->grading - 1]);
      }
    }
  }
}

/* 7 저장함수는  파일을 쓰기 모드로 열고
  총학점, 수강 과목 수 , 그레이드 , 패스페일 유무를 입력한다.

  중첩문을 이용해 코드로 과목을 찾고 , 파일에 쓰기모드를 이용해 총 학점과
  ,페스페일 유무에 따른 학점을 계산한다.
 */
void saveMyClass(int my[], int msize, struct st_class *c[], int csize) {
  FILE *file;
  file = fopen("my_classes.txt", "w");

  int total_credits = 0;
  int total_classes = msize;
  int credits_ApF = 0;
  int credits_PassF = 0;

  for (int i = 0; i < msize; i++) {
    for (int j = 0; j < csize; j++) {
      if (my[i] == c[j]->code) {
        fprintf(file, "%d %s %d %d\n", c[j]->code, c[j]->name, c[j]->unit,
                c[j]->grading);
        total_credits += c[j]->unit;
        if (c[j]->grading == 1) {
          credits_ApF += c[j]->unit;
        } else if (c[j]->grading == 2) {
          credits_PassF += c[j]->unit;
        }
        break;
      }
    }
  }

  fprintf(file, "Total credits: %d\n", total_credits);
  fprintf(file, "Total classes: %d\n", total_classes);
  fprintf(file, "Total credits for A+~F: %d\n", credits_ApF);
  fprintf(file, "Total credits for P/F: %d\n", credits_PassF);

  fclose(file);
}

////////////////////////////////////////////////////////////////////////////////

int main(void) {
  int no;
  struct st_class *classes[50];
  int myclass[10];
  int mycount = 0;
  srand(time(0));
  int count = loadData(classes);
  printf("> Load %d classes.\n", count);

  while (1) {
    printf("\n> Menu 1.List 2.Add 3.Modify 4.Search 5.Apply 6.My classes "
           "7.Save 0.Quit\n");
    printf(">> Menu? > ");
    scanf("%d", &no);

    if (no == 1) {
      printf("> 1.Class list (%d classes)\n", count);
      printAllClasses(classes, count);
    } else if (no == 2) {
      printf("> 2.Add a Class\n");
      count = addNewClass(classes, count);
    } else if (no == 3) {
      printf("> 3.Modify a Class\n");
      editClass(classes, count);
    } else if (no == 4) {
      printf("> 4.Search a Class\n");
      printf(">> Enter class name > ");
      char name[30];
      scanf("%s", name);
      findClasses(name, classes, count);
    } else if (no == 5) {
      printf("> 5.Apply a class\n");
      mycount = applyMyClasses(myclass, mycount, classes, count);
      printf("%d classes has been applied.\n", mycount);
    } else if (no == 6) {
      printf("> 6.My classes\n");
      printMyClasses(myclass, mycount, classes, count);
    } else if (no == 7) {
      printf("> 7.Save\n");
      saveMyClass(myclass, mycount, classes, count);
      printf("\n> All my classes ware saved to my_classes.txt.\n");
      saveAllClasses(classes, count);
      printf("\n> All of class list ware saved to classes.txt.\n");
    } else
      break;
  }
  return 0;
}
