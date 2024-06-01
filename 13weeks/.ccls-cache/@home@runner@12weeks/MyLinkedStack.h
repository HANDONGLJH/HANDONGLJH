#ifndef MY_LINKED_STACK_H
#define MY_LINKED_STACK_H

#include <iostream>
#include <stdexcept>

using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data) : data(data), next(nullptr) {}
};

class MyLinkedStack {
private:
  Node *stacktop;

public:
  MyLinkedStack() : stacktop(nullptr) {}

  ~MyLinkedStack() { clear(); }

  void clear() {
    while (stacktop) {
      Node *temp = stacktop;
      stacktop = stacktop->next;
      delete temp;
    }
  }

  bool isEmpty() const { return stacktop == nullptr; }

  void push(int elem) {
    Node *newNode = new Node(elem);
    newNode->next = stacktop;
    stacktop = newNode;
  }

  int pop() {
    if (isEmpty()) {
      throw runtime_error("스택이 비어 있습니다.");
    }
    int data = stacktop->data;
    Node *temp = stacktop;
    stacktop = stacktop->next;
    delete temp;
    return data;
  }

  int peek() const {
    if (isEmpty()) {
      throw runtime_error("스택이 비어 있습니다.");
    }
    return stacktop->data;
  }

  int getNodeCnt() const {
    int count = 0;
    Node *current = stacktop;
    while (current) {
      count++;
      current = current->next;
    }
    return count;
  }
};

#endif // MY_LINKED_STACK_H