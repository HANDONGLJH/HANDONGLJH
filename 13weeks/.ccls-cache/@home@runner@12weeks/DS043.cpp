#include "MyLinkedStack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  MyLinkedStack leftStack;
  MyLinkedStack rightStack;
  char input;

  cout << "문자열을 입력하세요 (종료하려면 q): ";

  while (cin >> input) {
    if (input == 'q') {
      break;
    } else if (input == '<') {
      if (!leftStack.isEmpty()) {
        rightStack.push(leftStack.pop());
      }
    } else if (input == '>') {
      if (!rightStack.isEmpty()) {
        leftStack.push(rightStack.pop());
      }
    } else {
      leftStack.push(input);
    }

    MyLinkedStack tempStack = leftStack;
    string result;

    while (!tempStack.isEmpty()) {
      result = tempStack.pop() + result;
    }

    result += '|'; // 커서를 표현

    tempStack = rightStack;
    while (!tempStack.isEmpty()) {
      result += tempStack.pop();
    }

    cout << "\r" << result << "  " << flush;
  }

  cout << endl << "프로그램 종료." << endl;
  return 0;
}