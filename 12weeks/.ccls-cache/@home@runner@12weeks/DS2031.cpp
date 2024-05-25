#include <cstdlib>
#include <iostream>

using namespace std;

// MyStack 클래스 정의
class MyStack {
private:
  int maxsize;
  int top;
  int *list;

public:
  MyStack(int size = 10) : maxsize(size), top(-1) { list = new int[maxsize]; }

  ~MyStack() { delete[] list; }

  void initialize() { top = -1; }

  bool isEmpty() const { return top == -1; }

  bool isFull() const { return top == maxsize - 1; }

  void push(const int &elem) {
    if (isFull()) {
      cout << "스택이 가득 찼습니다." << endl;
    } else {
      list[++top] = elem;
    }
  }

  int *pop() {
    if (isEmpty()) {
      cout << "스택이 비어 있습니다." << endl;
      return nullptr;
    } else {
      return &list[top--];
    }
  }

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
      break; // print 명령어를 수행하면 프로그램을 종료합니다.
    } else {
      cout << "올바른 명령어를 입력하세요." << endl;
    }
  }

  return 0;
}