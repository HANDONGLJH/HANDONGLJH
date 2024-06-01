#include <iostream>

using namespace std;

// Node 클래스 정의
class Node {
public:
  int data;
  Node *next;

  Node(int data) : data(data), next(nullptr) {}
};

// MyLinkedStack 클래스 정의
class MyLinkedStack {
private:
  Node *stacktop;

public:
  MyLinkedStack() : stacktop(nullptr) {}

  ~MyLinkedStack() { clear(); }

  void initialize() { clear(); }

  bool isEmpty() const { return stacktop == nullptr; }

  void push(const int &elem) {
    Node *newNode = new Node(elem);
    newNode->next = stacktop;
    stacktop = newNode;
  }

  void pop() {
    if (isEmpty()) {
      cout << "스택이 비어 있습니다." << endl;
      return;
    }
    Node *temp = stacktop;
    stacktop = stacktop->next;
    delete temp;
  }

  int peek() const {
    if (isEmpty()) {
      cout << "스택이 비어 있습니다." << endl;
      return -1; // 에러 시 -1 반환 (플래그 역할)
    }
    return stacktop->data;
  }

  int getNodeCnt() const {
    int count = 0;
    Node *current = stacktop;
    while (current != nullptr) {
      count++;
      current = current->next;
    }
    return count;
  }

  void clear() {
    while (!isEmpty()) {
      pop();
    }
  }

  void printAll() const {
    Node *current = stacktop;
    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }
};

int main() {
  MyLinkedStack stack;
  string command;
  int value;

  cout << "명령어를 입력하세요 (push ## , pop , peek , print , clear , q): "
       << endl;

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