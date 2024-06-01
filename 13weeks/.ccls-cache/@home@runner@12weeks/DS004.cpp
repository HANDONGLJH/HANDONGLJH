#include <iostream> // 입출력 스트림 라이브러리 포함

using namespace std; // 표준 네임스페이스 사용

// 점수 정보를 담는 구조체 정의
struct st_score {
  int kor, eng, math; // 국어, 영어, 수학 점수 저장
  int total;          // 총점 저장
  double average;     // 평균 저장
};

int main() {
  st_score score; // st_score 구조체 타입의 변수 score 선언

  // 점수 입력
  cout << "Enter scores for Korean, English, and Math: ";
  cin >> score.kor >> score.eng >> score.math;

  // 총점과 평균 계산
  score.total = score.kor + score.eng + score.math;
  score.average = score.total / 3.0;

  // 총점과 평균 출력
  cout << "Total: " << score.total << endl;
  cout << "Average: " << score.average << endl;

  // 각 과목의 합격 여부 출력
  cout << "Korean grade: " << (score.kor >= 70 ? "Pass" : "Fail") << endl;
  cout << "English grade: " << (score.eng >= 70 ? "Pass" : "Fail") << endl;
  cout << "Math grade: " << (score.math >= 70 ? "Pass" : "Fail") << endl;

  return 0;
}