#include <iostream>
using namespace std;

class MyCircularQueue {
private:
  int maxsize; // 큐의 최대 크기
  int front;   // 큐의 앞부분 인덱스
  int rear;    // 큐의 뒷부분 인덱스
  int *list;   // 요소를 저장할 배열

public:
  MyCircularQueue(int size = 10) : maxsize(size), front(0), rear(0) {
    list = new int[maxsize];
  }

  ~MyCircularQueue() { delete[] list; }

  void initialize() {
    front = 0;
    rear = 0;
  }

  bool isEmpty() const { return front == rear; }

  bool isFull() const { return (rear + 1) % maxsize == front; }

  void enqueue(const int &elem) {
    if (isFull()) {
      cout << "Queue is full" << endl;
      return;
    }
    list[rear] = elem;
    rear = (rear + 1) % maxsize;
  }

  void dequeue() {
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return;
    }
    front = (front + 1) % maxsize;
  }

  int Front() const {
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return -1; // 큐가 비어있으면 -1 반환
    }
    return list[front];
  }

  int Rear() const {
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return -1; // 큐가 비어있으면 -1 반환
    }
    return list[(rear - 1 + maxsize) % maxsize];
  }

  int size() const { return (rear - front + maxsize) % maxsize; }

  void print() const {
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return;
    }
    for (int i = front; i != rear; i = (i + 1) % maxsize) {
      cout << "[" << list[i] << "] ";
    }
    cout << endl;
  }

  void printDetail() const {
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
};

int main() {
  MyCircularQueue queue(8);

  // 초기 큐 상태 출력
  queue.printDetail();

  // Dequeue 한 번 수행 (빈 큐에서)
  cout << "Dequeue x1" << endl;
  queue.dequeue();
  queue.printDetail();

  // 10부터 70까지 10씩 증가하는 요소를 큐에 추가
  cout << "Enqueue x7 (10~70)" << endl;
  for (int i = 10; i <= 70; i += 10) {
    queue.enqueue(i);
  }
  queue.printDetail();

  return 0;
}