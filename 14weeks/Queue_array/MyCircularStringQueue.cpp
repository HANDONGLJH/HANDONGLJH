#include "MyCircularStringQueue.h"
#include <iostream>
using namespace std;

MyCircularStringQueue::MyCircularStringQueue(int size)
    : maxsize(size), front(0), rear(0) {
  list = new string[maxsize];
}

MyCircularStringQueue::~MyCircularStringQueue() { delete[] list; }

void MyCircularStringQueue::initialize() {
  front = 0;
  rear = 0;
}

bool MyCircularStringQueue::isEmpty() const { return front == rear; }

bool MyCircularStringQueue::isFull() const {
  return (rear + 1) % maxsize == front;
}

void MyCircularStringQueue::enqueue(const string &elem) {
  if (isFull()) {
    cout << "Queue is full" << endl;
    return;
  }
  list[rear] = elem;
  rear = (rear + 1) % maxsize;
}

void MyCircularStringQueue::dequeue() {
  if (isEmpty()) {
    cout << "Queue is empty" << endl;
    return;
  }
  front = (front + 1) % maxsize;
}

string MyCircularStringQueue::Front() const {
  if (isEmpty()) {
    cout << "Queue is empty" << endl;
    return "";
  }
  return list[front];
}

string MyCircularStringQueue::Rear() const {
  if (isEmpty()) {
    cout << "Queue is empty" << endl;
    return "";
  }
  return list[(rear - 1 + maxsize) % maxsize];
}

int MyCircularStringQueue::size() const {
  return (rear - front + maxsize) % maxsize;
}

void MyCircularStringQueue::print() const {
  if (isEmpty()) {
    cout << "Queue is empty" << endl;
    return;
  }
  for (int i = front; i != rear; i = (i + 1) % maxsize) {
    cout << "[" << list[i] << "] ";
  }
  cout << endl;
}

void MyCircularStringQueue::printDetail() const {
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