#include <fstream>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// DS031.cpp에서 이미 제공된 MyStack 클래스를 사용합니다.
class MyStack {
private:
  int maxsize;
  int top;
  string *list;

public:
  MyStack(int size = 10) : maxsize(size), top(-1) {
    list = new string[maxsize];
  }

  ~MyStack() { delete[] list; }

  void initialize() { top = -1; }

  bool isEmpty() const { return top == -1; }

  bool isFull() const { return top == maxsize - 1; }

  void push(const string &elem) {
    if (isFull()) {
      cout << "스택이 가득 찼습니다." << endl;
    } else {
      list[++top] = elem;
    }
  }

  string pop() {
    if (isEmpty()) {
      cout << "스택이 비어 있습니다." << endl;
      return "";
    } else {
      return list[top--];
    }
  }

  void clear() { initialize(); }

  void print() const {
    if (isEmpty()) {
      cout << "스택이 비어 있습니다." << endl;
    } else {
      for (int i = 0; i <= top; ++i) {
        cout << list[i] << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  ifstream inputFile("data.txt");
  if (!inputFile) {
    cerr << "파일을 열 수 없습니다." << endl;
    return 1;
  }

  MyStack stack(100); // 최대 100명의 학생을 처리할 수 있는 스택
  double maxGPA = numeric_limits<double>::lowest();
  string name;
  double gpa;

  while (inputFile >> gpa >> name) {
    if (gpa > maxGPA) {
      maxGPA = gpa;
      stack.clear();
      stack.push(name);
    } else if (gpa == maxGPA) {
      stack.push(name);
    }
  }

  inputFile.close();

  cout << "가장 높은 GPA: " << maxGPA << endl;
  cout << "해당 학생들:" << endl;
  stack.print();

  return 0;
}