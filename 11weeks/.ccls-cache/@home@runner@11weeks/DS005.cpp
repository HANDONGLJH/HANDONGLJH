#include <cctype> // 문자 처리 함수 (isspace, isalpha, tolower)를 사용하기 위해 포함
#include <cstring> // 문자열 처리 함수 (strlen)를 사용하기 위해 포함
#include <iostream> // 입출력 함수 (cin, cout)을 사용하기 위해 포함

using namespace std; // 표준 네임스페이스 사용

int main() {
  // 최대 50자의 문장을 저장할 배열 (널 종단 문자 포함 총 51자 크기)
  char sentence[51];

  // 알파벳 개수를 저장할 배열 (a~z의 26자)
  int alphabet_count[26] = {0};

  // 공백 문자의 개수를 셀 정수 변수
  int space_count = 0;

  // 문장 입력 받기
  cout << "Enter a sentence (max 50 characters): ";
  cin.getline(sentence, 51);

  // 문장 분석하기
  for (int i = 0; i < strlen(sentence); i++) {
    // 현재 문자가 공백인지 확인
    if (isspace(sentence[i])) {
      space_count++;
    }
    // 현재 문자가 알파벳인지 확인
    else if (isalpha(sentence[i])) {
      // 알파벳 문자를 소문자로 변환한 후 해당 알파벳 개수 증가
      alphabet_count[tolower(sentence[i]) - 'a']++;
    }
  }

  // 결과 출력
  cout << "Spaces: " << space_count << endl;

  // 알파벳 개수 출력
  for (char c = 'a'; c <= 'z'; c++) {
    cout << c << ": " << alphabet_count[c - 'a'] << endl;
  }

  return 0;
}