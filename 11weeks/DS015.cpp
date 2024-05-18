#include <cstring>
#include <iostream>

using namespace std;

// 문자열을 저장하는 구조체
struct String {
  char str[256];
};

// 공백과 탭을 다루기 위한 구조체
struct TrimmedString {
  char str[256];
};

// 함수 프로토타입 정의
void ltrim(String &input, TrimmedString &output);
void rtrim(TrimmedString &input);
int lengthOfLastWord(const TrimmedString &input);

int main() {
  String inputString;
  TrimmedString trimmedString;

  // 문자열 입력받기
  cout << "문자열을 입력하세요: ";
  cin.getline(inputString.str, 256);

  // 문자열 앞뒤의 공백과 탭 문자 제거
  ltrim(inputString, trimmedString);
  rtrim(trimmedString);

  // 마지막 단어의 길이 구하기
  int lastWordLength = lengthOfLastWord(trimmedString);

  // 결과 출력
  cout << "마지막 단어의 길이: " << lastWordLength << endl;

  return 0;
}

// 문자열 앞의 공백과 탭 문자를 제거하는 함수
void ltrim(String &input, TrimmedString &output) {
  int start = 0;
  // 공백이나 탭 문자가 아닌 문자가 나올 때까지 인덱스를 증가
  while (input.str[start] == ' ' || input.str[start] == '\t') {
    start++;
  }
  // 문자열을 앞으로 이동
  int i = 0;
  while (input.str[start + i] != '\0') {
    output.str[i] = input.str[start + i];
    i++;
  }
  output.str[i] = '\0'; // 마지막에 null 문자 추가
}

// 문자열 뒤의 공백과 탭 문자를 제거하는 함수
void rtrim(TrimmedString &input) {
  int end = strlen(input.str) - 1;
  // 공백이나 탭 문자가 아닌 문자가 나올 때까지 인덱스를 감소
  while (end >= 0 && (input.str[end] == ' ' || input.str[end] == '\t')) {
    end--;
  }
  input.str[end + 1] = '\0'; // 문자열 끝을 null 문자로 설정
}

// 마지막 단어의 길이를 구하는 함수
int lengthOfLastWord(const TrimmedString &input) {
  int length = strlen(input.str);
  int end = length - 1;

  // 문자열 끝에서부터 공백이나 탭을 건너뜀
  while (end >= 0 && (input.str[end] == ' ' || input.str[end] == '\t')) {
    end--;
  }

  // 마지막 단어의 시작 위치 찾기
  int start = end;
  while (start >= 0 && input.str[start] != ' ' && input.str[start] != '\t') {
    start--;
  }

  // 마지막 단어의 길이 반환
  return end - start;
}