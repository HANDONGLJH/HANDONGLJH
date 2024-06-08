#include "MyCircularStringQueue.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {
  ifstream inputFile("data.txt");
  if (!inputFile) {
    cerr << "파일을 열 수 없습니다." << endl;
    return 1;
  }

  MyCircularStringQueue queue(100); // 최대 100명의 학생을 처리할 수 있는 큐
  double maxGPA = numeric_limits<double>::lowest();
  string name;
  double gpa;

  while (inputFile >> gpa >> name) {
    if (gpa > maxGPA) {
      maxGPA = gpa;
      queue.initialize();  // 새로운 최고 GPA면 큐 초기화
      queue.enqueue(name); // 이름을 큐에 추가
    } else if (gpa == maxGPA) {
      queue.enqueue(name); // 같은 최고 GPA면 큐에 추가
    }
  }

  inputFile.close();

  cout << "가장 높은 GPA: " << maxGPA << endl;
  cout << "해당 학생들:" << endl;
  queue.print();

  return 0;
}