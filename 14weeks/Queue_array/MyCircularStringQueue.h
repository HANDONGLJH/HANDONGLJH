#ifndef MYCIRCULARSTRINGQUEUE_H
#define MYCIRCULARSTRINGQUEUE_H

#include <string>
using namespace std;

class MyCircularStringQueue {
private:
  int maxsize;  // 큐의 최대 크기
  int front;    // 큐의 앞부분 인덱스
  int rear;     // 큐의 뒷부분 인덱스
  string *list; // 요소를 저장할 배열

public:
  MyCircularStringQueue(int size = 10);
  ~MyCircularStringQueue();

  void initialize();
  bool isEmpty() const;
  bool isFull() const;
  void enqueue(const string &elem);
  void dequeue();
  string Front() const;
  string Rear() const;
  int size() const;
  void print() const;
  void printDetail() const;
};

#endif