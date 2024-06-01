#include "MyLinkedStack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    MyLinkedStack stack;
    string command;
    int value;

    cout << "명령어를 입력하세요 (push ## , pop , peek , print , clear , q): " << endl;

    while (cin >> command) {
        if (command == "push") {
            cin >> value;
            stack.push(value);
        } else if (command == "pop") {
            stack.pop();
        } else if (command == "peek") {
            cout << "peek: " << stack.peek() << endl; 
        } else if (command == "print") {
            stack.printAll();
        } else if (command == "clear") {
            stack.clear();
            cout << "스택을 초기화했습니다." << endl;
        } else if (command == "q") {
            break;
        } else {
            cout << "올바른 명령어를 입력하세요." << endl;
        }
    }

    return 0;
}