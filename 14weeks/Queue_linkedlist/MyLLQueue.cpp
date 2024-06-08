#include "MyLLQueue.h"

template <typename T>
MyLLQueue<T>::MyLLQueue() : front(nullptr), rear(nullptr), length(0) {}

template <typename T> MyLLQueue<T>::~MyLLQueue() {
  while (!isEmpty()) {
    dequeue();
  }
}

template <typename T> bool MyLLQueue<T>::isEmpty() const { return length == 0; }

template <typename T> int MyLLQueue<T>::size() const { return length; }

template <typename T> void MyLLQueue<T>::enqueue(const T &elem) {
  Node *newNode = new Node(elem);
  if (rear) {
    rear->next = newNode;
  } else {
    front = newNode;
  }
  rear = newNode;
  length++;
}

template <typename T> void MyLLQueue<T>::dequeue() {
  if (isEmpty()) {
    std::cout << "Queue is empty" << std::endl;
    return;
  }
  Node *temp = front;
  front = front->next;
  if (!front) {
    rear = nullptr;
  }
  delete temp;
  length--;
}

template <typename T> T MyLLQueue<T>::Front() const {
  if (isEmpty()) {
    throw std::out_of_range("Queue is empty");
  }
  return front->data;
}

template <typename T> T MyLLQueue<T>::Rear() const {
  if (isEmpty()) {
    throw std::out_of_range("Queue is empty");
  }
  return rear->data;
}

template <typename T> void MyLLQueue<T>::print() const {
  if (isEmpty()) {
    std::cout << "Queue is empty" << std::endl;
    return;
  }
  Node *temp = front;
  while (temp) {
    std::cout << "[" << temp->data << "] ";
    temp = temp->next;
  }
  std::cout << std::endl;
}