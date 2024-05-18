#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int findRoom(int persons[5]);
void printReport(string mn[10], int mr[10], int mc, string wn[10], int wr[10],
                 int wc);

int main() {
  string mnames[10];      // names of all male students (max. 10)
  string wnames[10];      // names of all female students (max. 10)
  int mroom[10];          // room numbers assigned all male students
  int wroom[10];          // room numbers assigned all female students
  int person[2][5] = {0}; // number of persons assigned to all rooms (two floors
                          // & each five rooms)
  int mcount = 0, wcount = 0; // number of all persons (male, female)
  int menu;

  srand(time(0));
  cout << "===========================================" << endl;
  cout << "생활관 호실 배정 프로그램" << endl;
  cout << "===========================================" << endl;
  while (1) {
    cout << "메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ";
    cin >> menu;
    if (menu == 0)
      break;
    else if (menu == 1) {
      if (mcount >= 10) {
        cout << "정원 초과입니다. 등록불가!" << endl;
        continue;
      }
      cout << "학생 이름은? > ";
      cin >> mnames[mcount];
      int roomno = findRoom(person[0]);
      if (roomno != -1) {
        person[0][roomno - 1]++;
        mroom[mcount] = 100 + roomno;
        cout << mnames[mcount] << " 학생 " << mroom[mcount]
             << "호실 배정되었습니다." << endl;
        mcount++;
      } else {
        cout << "빈 호실이 없습니다." << endl;
      }
    } else if (menu == 2) {
      if (wcount >= 10) {
        cout << "정원 초과입니다. 등록불가!" << endl;
        continue;
      }
      cout << "학생 이름은? > ";
      cin >> wnames[wcount];
      int roomno = findRoom(person[1]);
      if (roomno != -1) {
        person[1][roomno - 1]++;
        wroom[wcount] = 200 + roomno;
        cout << wnames[wcount] << " 학생 " << wroom[wcount]
             << "호실 배정되었습니다." << endl;
        wcount++;
      } else {
        cout << "빈 호실이 없습니다." << endl;
      }
    }
  }

  cout << "===========================================" << endl;
  cout << "생활관 호실 배정 결과는 다음과 같습니다." << endl;
  cout << "===========================================" << endl;
  printReport(mnames, mroom, mcount, wnames, wroom, wcount);

  return 0;
}

int findRoom(int persons[5]) {
  int availableRooms[5];
  int availableCount = 0;

  for (int i = 0; i < 5; i++) {
    if (persons[i] < 2) {
      availableRooms[availableCount++] = i + 1;
    }
  }

  if (availableCount == 0) {
    return -1;
  } else {
    int randomIndex = rand() % availableCount;
    return availableRooms[randomIndex];
  }
}

void printReport(string mn[10], int mr[10], int mc, string wn[10], int wr[10],
                 int wc) {
  cout << "남학생 명단 및 호실:" << endl;
  for (int i = 0; i < mc; i++) {
    cout << mn[i] << " - " << mr[i] << "호" << endl;
  }

  cout << "여학생 명단 및 호실:" << endl;
  for (int i = 0; i < wc; i++) {
    cout << wn[i] << " - " << wr[i] << "호" << endl;
  }

  cout << "호실별 배정 명단:" << endl;
  cout << "1층 (남학생):" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "Room " << (100 + i + 1) << ": ";
    for (int j = 0; j < mc; j++) {
      if (mr[j] == 100 + i + 1) {
        cout << mn[j] << " ";
      }
    }
    cout << endl;
  }

  cout << "2층 (여학생):" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "Room " << (200 + i + 1) << ": ";
    for (int j = 0; j < wc; j++) {
      if (wr[j] == 200 + i + 1) {
        cout << wn[j] << " ";
      }
    }
    cout << endl;
  }
}