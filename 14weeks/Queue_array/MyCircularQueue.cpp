#include "MyCircularQueue.h"
#include <iostream>
using namespace std;

MyCircularQueue::MyCircularQueue(int size) : maxsize(size), front(0), rear(0) {
  list = new int[maxsize];
}

MyCircularQueue::~MyCircularQueue() { delete[] list; }

void MyCircularQueue::initialize() {
  front = 0;
  rear = 0;
}

bool MyCircularQueue::isEmpty() const { return front == rear; }

bool MyCircularQueue::isFull() const { return (rear + 1) % maxsize == front; }

void MyCircularQueue::enqueue(const int &elem) {
  if (isFull()) {
    cout << "Queue is full" << endl;
    return;
  }
  list[rear] = elem;
  rear = (rear + 1) % maxsize;
}

void MyCircularQueue::dequeue() {
  if (isEmpty()) {
    cout << "Queue is empty" << endl;
    return;
  }
  front = (front + 1) % maxsize;
}

int MyCircularQueue::Front() const {
  if (isEmpty()) {
    cout << "Queue is empty" << endl;
    return -1;
  }
  return list[front];
}

int MyCircularQueue::Rear() const {
  if (isEmpty()) {
    cout << "Queue is empty" << endl;
    return -1;
  }
  return list[(rear - 1 + maxsize) % maxsize];
}

int MyCircularQueue::size() const { return (rear - front + maxsize) % maxsize; }

void MyCircularQueue::print() const {
  if (isEmpty()) {
    cout << "Queue is empty" << endl;
    return;
  }
  for (int i = front; i != rear; i = (i + 1) % maxsize) {
    cout << "[" << list[i] << "] ";
  }
  cout << endl;
}

void MyCircularQueue::printDetail() const {
  cout << "Size : " << size() << endl;
  cout << "Queue : ";
  for (int i = front; i != rear; i = (i + 1) % maxsize) {
    cout << "[" << list[i] << "] ";
  }
  cout << endl;

  cout << "index : ";
  for (int i = 0; i < size(); ++i) {
    cout << (front + i) % maxsize + 1 << " ";
  }
  cout << endl;

  cout << "front : " << front << " , rear : " << rear << endl;
}