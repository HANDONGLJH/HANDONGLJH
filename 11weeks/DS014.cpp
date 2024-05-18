#include <cstring>
#include <iostream>

using namespace std;

// 문자열 앞의 공백과 탭 문자를 제거하는 함수
void ltrim(char *str);

// 문자열 뒤의 공백과 탭 문자를 제거하는 함수
void rtrim(char *str);

// 문자열 앞뒤의 공백과 탭 문자를 모두 제거하는 함수
void trim(char *str);

int main() {
  // 사용자로부터 문자열 입력받기
  char input[256];
  cout << "문자열을 입력하세요: ";
  cin.getline(input, 256);

  // 문자열 앞뒤의 공백과 탭 문자 제거
  trim(input);

  // 결과 출력
  cout << "Trimmed 문자열: \"" << input << "\"" << endl;

  return 0;
}

// 문자열 앞의 공백과 탭 문자를 제거하는 함수
void ltrim(char *str) {
  int start = 0;
  // 공백이나 탭 문자가 아닌 문자가 나올 때까지 인덱스를 증가
  while (str[start] == ' ' || str[start] == '\t') {
    start++;
  }
  // 문자열을 앞으로 이동
  if (start > 0) {
    int i;
    for (i = 0; str[start + i] != '\0'; i++) {
      str[i] = str[start + i];
    }
    str[i] = '\0'; // 마지막에 null 문자 추가
  }
}

// 문자열 뒤의 공백과 탭 문자를 제거하는 함수
void rtrim(char *str) {
  int end = strlen(str) - 1;
  // 공백이나 탭 문자가 아닌 문자가 나올 때까지 인덱스를 감소
  while (end >= 0 && (str[end] == ' ' || str[end] == '\t')) {
    end--;
  }
  str[end + 1] = '\0'; // 문자열 끝을 null 문자로 설정
}

// 문자열 앞뒤의 공백과 탭 문자를 모두 제거하는 함수
void trim(char *str) {
  ltrim(str);
  rtrim(str);
}