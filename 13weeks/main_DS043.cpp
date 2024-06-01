#include "MyLinkedStack.h"
#include <iostream>

using namespace std;

void printStack(MyLinkedStack &leftStack, MyLinkedStack &rightStack) {
    MyLinkedStack tempStack;
    string result;

    Node *current = leftStack.getTop(); // 수정된 부분
    while (current != nullptr) {
        tempStack.push(current->data);
        current = current->next;
    }

    while (!tempStack.isEmpty()) {
        result = static_cast<char>(tempStack.pop()) + result;
    }

    result += '|';

    current = rightStack.getTop(); // 수정된 부분
    while (current != nullptr) {
        result += static_cast<char>(current->data);
        current = current->next;
    }

    cout << "\r" << result << "  " << flush;
}

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

        printStack(leftStack, rightStack);
    }

    cout << endl << "프로그램 종료." << endl;
    return 0;
}