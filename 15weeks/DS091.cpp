#include <iostream>
#include <stack>
#include <string>

using namespace std;

void processString(const string &input) {
    stack<char> leftStack, rightStack;

    for (char ch : input) {
        if (ch == '<') {
            if (!leftStack.empty()) {
                rightStack.push(leftStack.top());
                leftStack.pop();
            }
        } else if (ch == '>') {
            if (!rightStack.empty()) {
                leftStack.push(rightStack.top());
                rightStack.pop();
            }
        } else {
            leftStack.push(ch);
        }
    }

    // 왼쪽 스택의 내용을 결과 문자열에 추가
    string result;
    while (!leftStack.empty()) {
        result += leftStack.top();
        leftStack.pop();
    }
    reverse(result.begin(), result.end());

    // 오른쪽 스택의 내용을 결과 문자열에 추가
    while (!rightStack.empty()) {
        result += rightStack.top();
        rightStack.pop();
    }

    cout << "=>" << result << endl;
}

int main() {
    string input;
    while (true) {
        cout << "문자열을 입력 (종료는 'exit'): ";
        getline(cin, input);
        if (input == "exit")
            break;
        processString(input);
    }
    return 0;
}