#include "MyCircularQueue.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  int queueSize;
  cin >> queueSize;

  MyCircularQueue queue(queueSize);
  string command;
  int value;

  while (true) {
    cin >> command;

    if (command == "q") {
      break;
    } else if (command.substr(0, 2) == "en") {
      value = stoi(command.substr(2));
      queue.enqueue(value);
    } else if (command == "de") {
      queue.dequeue();
    } else if (command == "front") {
      cout << queue.Front() << endl;
    } else if (command == "rear") {
      cout << queue.Rear() << endl;
    } else if (command == "size") {
      cout << queue.size() << endl;
    } else if (command == "empty") {
      cout << queue.isEmpty() << endl;
    } else if (command == "print") {
      queue.print();
    } else {
      cout << "Unknown command" << endl;
    }
  }

  return 0;
}