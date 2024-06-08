#include "MyLLQueue.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu() {

    cout << "1. Enqueue 2. Dequeue 3. Show front 4. Show rear 5.Print 6. Quit "  << endl;
   
}

int main() {
    MyLLQueue<int> queue;
    int choice = 0;
    int value;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                try {
                    queue.dequeue();
                    cout << "Dequeued successfully." << endl;
                } catch (const std::out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 3:
                try {
                    cout << "Front element: " << queue.Front() << endl;
                } catch (const std::out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 4:
                try {
                    cout << "Rear element: " << queue.Rear() << endl;
                } catch (const std::out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 5:
                queue.print();
                break;
            case 6:
                cout << "Quitting the program." << endl;
                break;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}