#include "MyStack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int size;
    cout << "스택의 크기를 입력하세요: ";
    cin >> size;

    MyStack stack(size);

    string command;
    int value;

    while (cin >> command) {
        if (command == "push") {
            cin >> value;
            stack.push(value);
        } else if (command == "pop") {
            stack.pop();
        } else if (command == "print") {
            stack.print();
            break; 
        } else {
            cout << "올바른 명령어를 입력하세요." << endl;
        }
    }

    return 0;
}