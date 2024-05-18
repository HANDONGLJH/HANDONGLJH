#include <iostream>

using namespace std;

int main() {
  int month, day;
  int day_count;

  // 월 일 입력
  cin >> month >> day;

  // 날짜 계산
  switch (month) {
  case 1:
    day_count = day;
    break;
  case 2:
    day_count = 31 + day;
    break;
  case 3:
    day_count = 31 + 28 + day;
    break;
  case 4:
    day_count = 31 + 28 + 31 + day;
    break;
  case 5:
    day_count = 31 + 28 + 31 + 30 + day;
    break;
  case 6:
    day_count = 31 + 28 + 31 + 30 + 31 + day;
    break;
  case 7:
    day_count = 31 + 28 + 31 + 30 + 31 + 30 + day;
    break;
  case 8:
    day_count = 31 + 28 + 31 + 30 + 31 + 30 + 31 + day;
    break;
  case 9:
    day_count = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day;
    break;
  case 10:
    day_count = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
    break;
  case 11:
    day_count = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
    break;
  case 12:
    day_count = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
    break;
  }

  // 결과
  cout << "The day number in the year is: " << day_count << endl;

  return 0;
}