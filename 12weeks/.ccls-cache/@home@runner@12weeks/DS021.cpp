#include <iostream> // 입출력 스트림 라이브러리 포함

using namespace std;

class Student {
private:
  // 국어, 영어, 수학 점수 배열의 평균을 계산하여 반환하는 함수
  double getAvg() const {
    double sum = score[0] + score[1] + score[2];
    return sum / 3.0;
  }

public:
  string name;  // 학생 이름
  string sid;   // 학생 학번
  int score[3]; // 국어, 영어, 수학 점수 배열

  // 학생 정보를 출력하는 함수
  void print() const {
    cout << sid << ", " << name << endl;     // 학번과 이름 출력
    cout << "Average: " << getAvg() << endl; // 평균 점수 출력
  }
};

int main() {
  Student student; // Student 객체 생성

  // 학번과 점수 입력 받기
  cout << "학번, 국어, 영어, 수학 점수를 입력하세요: ";
  cin >> student.sid >> student.score[0] >> student.score[1] >>
      student.score[2];

  // 이름 입력 받기
  cout << "이름을 입력하세요: ";
  cin.ignore(); // 이전 입력 버퍼 비우기
  getline(cin, student.name);

  // 학생 정보 출력
  student.print();

  return 0;
}