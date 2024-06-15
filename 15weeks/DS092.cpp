#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
  MaxHeap(int capacity);

  void insert(int value);
  int deleteMax();
  void maxHeapify(int rootIndex);

private:
  vector<int> heap;
  int capacity;
  int parent(int i) { return (i - 1) / 2; }
  int leftChild(int i) { return 2 * i + 1; }
  int rightChild(int i) { return 2 * i + 2; }
};

MaxHeap::MaxHeap(int capacity) { this->capacity = capacity; }

void MaxHeap::insert(int value) {
  if (heap.size() == capacity) {
    cout << "heap is full" << endl;
    return;
  }

  heap.push_back(value);
  int i = heap.size() - 1;

  while (i != 0 && heap[parent(i)] < heap[i]) {
    swap(heap[i], heap[parent(i)]);
    i = parent(i);
  }
}

int MaxHeap::deleteMax() {
  if (heap.size() == 0) {
    cout << "Heap is empty" << endl;
    return -1; // error value
  }

  int maxValue = heap[0];
  heap[0] = heap.back();
  heap.pop_back();
  maxHeapify(0);
  return maxValue;
}

void MaxHeap::maxHeapify(int rootIndex) {
  int largest = rootIndex;
  int left = leftChild(rootIndex);
  int right = rightChild(rootIndex);

  if (left < heap.size() && heap[left] > heap[largest])
    largest = left;
  if (right < heap.size() && heap[right] > heap[largest])
    largest = right;

  if (largest != rootIndex) {
    swap(heap[rootIndex], heap[largest]);
    maxHeapify(largest);
  }
}

int main() {
  int n, k;
  cout << "정수의 개수와 K를 입력: ";
  cin >> n >> k;

  vector<int> numbers(n);
  cout << "정수 목록을 입력: ";
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }

  MaxHeap maxHeap(n);
  for (int i = 0; i < n; i++) {
    maxHeap.insert(numbers[i]);
  }

  int kthLargest;
  for (int i = 0; i < k; i++) {
    kthLargest = maxHeap.deleteMax();
  }

  cout << "배열에서 " << k << "번째로 큰 수는: " << kthLargest << endl;

  return 0;
}