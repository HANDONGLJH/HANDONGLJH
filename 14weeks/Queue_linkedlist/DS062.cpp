#include "MyLLQueue.h"
#include <iostream>

using namespace std;

int fibonacci(int n) {
  if (n == 1 || n == 2) {
    cout << "f(" << n << ") = 1" << endl;
    return 1;
  }

  MyLLQueue<int> queue;
  queue.enqueue(1); // f(1)
  queue.enqueue(1); // f(2)

  cout << "f(1) = 1" << endl;
  cout << "f(2) = 1" << endl;

  for (int i = 3; i <= n; ++i) {
    int first = queue.Front();
    queue.dequeue();
    int second = queue.Front();
    int new_value = first + second;
    queue.enqueue(new_value);

    // Print the calculation step by step
    cout << "f(" << i << ") = " << first << " + " << second << " = "
         << new_value << endl;
  }

  return queue.Rear();
}

int main() {
  int n;
  cout << " (n): ";
  cin >> n;

  if (n <= 0 || n > 20) {
    cout << "Please enter a positive integer less than or equal to 20." << endl;
    return 1;
  }

  int result = fibonacci(n);
  cout << "Fibonacci number f(" << n << ") is: " << result << endl;

  return 0;
}