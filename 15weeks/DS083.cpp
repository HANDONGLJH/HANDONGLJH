#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
  MaxHeap(int capacity);

  void insert(int value);
  void deleteMax();
  void printHeap();

private:
  vector<int> heap;
  int capacity;

  void maxHeapify(int rootIndex);
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

void MaxHeap::deleteMax() {
  if (heap.size() == 0) {
    cout << "Heap is empty" << endl;
    return;
  }

  heap[0] = heap.back();
  heap.pop_back();
  maxHeapify(0);
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

void MaxHeap::printHeap() {
  for (int i = 0; i < heap.size(); i++)
    cout << heap[i] << " ";
  cout << endl;
}

int main() {
  MaxHeap maxHeap(20);
  int choice;
  while (true) {
    cout << "1. Insert 2. Delete Max 3. Print Heap 4. Exit > ";
    cin >> choice;
    if (choice == 1) {
      int value;
      cout << "Enter value to insert: ";
      cin >> value;
      maxHeap.insert(value);
    } else if (choice == 2) {
      maxHeap.deleteMax();
    } else if (choice == 3) {
      maxHeap.printHeap();
    } else if (choice == 4) {
      break;
    } else {
      cout << "Invalid choice. Try again." << endl;
    }
  }
  return 0;
}