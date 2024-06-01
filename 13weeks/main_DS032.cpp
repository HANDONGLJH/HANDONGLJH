#include "StringStack.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("data.txt");
    if (!inputFile) {
        cerr << "파일을 열 수 없습니다." << endl;
        return 1;
    }

    StringStack stack(100); // 최대 100명의 학생을 처리할 수 있는 스택
    double maxGPA = numeric_limits<double>::lowest();
    string name;
    double gpa;

    while (inputFile >> gpa >> name) {
        if (gpa > maxGPA) {
            maxGPA = gpa;
            stack.clear();
            stack.push(name); // 이름을 스택에 푸시
        } else if (gpa == maxGPA) {
            stack.push(name); // 이름을 스택에 푸시
        }
    }

    inputFile.close();

    cout << "가장 높은 GPA: " << maxGPA << endl;
    cout << "해당 학생들:" << endl;
    stack.print();

    return 0;
}