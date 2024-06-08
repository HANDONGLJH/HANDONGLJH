#ifndef MYCIRCULARQUEUE_H
#define MYCIRCULARQUEUE_H

class MyCircularQueue {
private:
  int maxsize;
  int front;
  int rear;
  int *list;

public:
  MyCircularQueue(int size = 10);
  ~MyCircularQueue();

  void initialize();
  bool isEmpty() const;
  bool isFull() const;
  void enqueue(const int &elem);
  void dequeue();
  int Front() const;
  int Rear() const;
  int size() const;
  void print() const;
  void printDetail() const;
};

#endif