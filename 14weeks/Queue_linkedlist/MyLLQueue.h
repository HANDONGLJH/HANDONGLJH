#ifndef MYLLQUEUE_H
#define MYLLQUEUE_H

#include <iostream>

template <typename T> class MyLLQueue {
private:
  struct Node {
    T data;
    Node *next;
    Node(T val) : data(val), next(nullptr) {}
  };

  Node *front;
  Node *rear;
  int length;

public:
  MyLLQueue();
  ~MyLLQueue();

  bool isEmpty() const;
  int size() const;
  void enqueue(const T &elem);
  void dequeue();
  T Front() const;
  T Rear() const;
  void print() const;
};

#include "MyLLQueue.cpp"
#endif