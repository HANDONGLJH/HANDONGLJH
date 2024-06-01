#include "MyLinkedStack.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int evaluatePostfix(const string &expression) {
  MyLinkedStack stack;
  istringstream iss(expression);
  string token;

  while (iss >> token) {
    if (token[0] == '#') {
      int num = stoi(token.substr(1));
      stack.push(num);
    } else if (token == "+") {
      if (stack.getNodeCnt() < 2) {
        throw logic_error("연산자가 너무 많습니다.");
      }
      int b = stack.pop();
      int a = stack.pop();
      stack.push(a + b);
    } else if (token == "-") {
      if (stack.getNodeCnt() < 2) {
        throw logic_error("연산자가 너무 많습니다.");
      }
      int b = stack.pop();
      int a = stack.pop();
      stack.push(a - b);
    } else if (token == "*") {
      if (stack.getNodeCnt() < 2) {
        throw logic_error("연산자가 너무 많습니다.");
      }
      int b = stack.pop();
      int a = stack.pop();
      stack.push(a * b);
    } else if (token == "/") {
      if (stack.getNodeCnt() < 2) {
        throw logic_error("연산자가 너무 많습니다.");
      }
      int b = stack.pop();
      if (b == 0) {
        throw logic_error("0으로 나눴습니다.");
      }
      int a = stack.pop();
      stack.push(a / b);
    } else if (token == "=") {
      if (stack.getNodeCnt() != 1) {
        throw logic_error("연산자가 너무 많습니다.");
      }
      return stack.pop();
    } else {
      throw logic_error("표현 오류");
    }
  }
  throw logic_error("표현 오류");
}

int main() {
  ifstream inputFile("expressions.txt");
  if (!inputFile) {
    cerr << "파일을 열 수 없습니다." << endl;
    return 1;
  }

  string line;
  while (getline(inputFile, line)) {
    try {
      int result = evaluatePostfix(line);
      cout << "결과: " << result << endl;
    } catch (const exception &e) {
      cout << "에러: " << e.what() << endl;
    }
  }

  inputFile.close();
  return 0;
}