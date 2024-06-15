#ifndef MYLINKEDSTACK_H
#define MYLINKEDSTACK_H

struct Node {
  int data;
  Node *next;
  Node(int data);
};

class MyLinkedStack {
private:
  Node *stacktop;

public:
  MyLinkedStack();
  ~MyLinkedStack();
  void initialize();
  bool isEmpty() const;
  void push(const int &elem);
  int pop();
  int peek() const;
  void clear();
  void printAll() const;
  int getNodeCnt() const;
  Node *getTop() const;
};

#endif