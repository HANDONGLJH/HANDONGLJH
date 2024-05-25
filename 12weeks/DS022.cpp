#include <iostream>

using namespace std;

class Student {
private:
  string name;  // 학생 이름
  int lc_score; // LC 점수
  int rc_score; // RC 점수

  // 점수 유효성 체크 함수
  int validateScore(const string &prompt) {
    int score;
    while (true) {
      cout << prompt;
      cin >> score;
      if (score >= 0 && score <= 495) {
        break;
      } else {
        cout << "올바른 점수를 입력하세요 (0 ~ 495):" << endl;
      }
    }
    return score;
  }

public:
  // 기본 생성자
  Student() : lc_score(0), rc_score(0) {}

  // 이름과 점수를 입력받는 생성자
  Student(string name, int lc, int rc)
      : name(name), lc_score(lc), rc_score(rc) {}

  // 이름만 입력받는 생성자
  Student(string name) : name(name), lc_score(0), rc_score(0) {}

  // 모든 변수 초기화 함수
  void setAll(string name, int lc, int rc) {
    this->name = name;
    this->lc_score = lc;
    this->rc_score = rc;
  }

  // 학생 정보 입력 받기
  void input() {
    cout << "학생 이름을 입력하세요: ";
    cin.ignore(); // 입력 버퍼 완전히 비우기
    getline(cin, name);
    lc_score = validateScore("LC 점수를 입력하세요: ");
    rc_score = validateScore("RC 점수를 입력하세요: ");
  }

  // 학생 정보 출력
  void print() const {
    cout << "총점: " << lc_score + rc_score << endl;
  }

  // 개별 과목 패스 여부를 출력 및 총점만 출력
  void passOrFail() const {
    if (lc_score >= 350) {
      cout << "LC 합격" << endl;
    } else {
      cout << "LC 불합격" << endl;
    }
    if (rc_score >= 350) {
      cout << "RC 합격" << endl;
    } else {
      cout << "RC 불합격" << endl;
    }
    cout << "총점: " << lc_score + rc_score << endl;
  }
};

int main() {
  Student student;      // Student 객체 생성
  student.input();      // 학생 정보 입력
  student.passOrFail(); // 패스 여부 판단 및 총점 출력

  return 0;
}