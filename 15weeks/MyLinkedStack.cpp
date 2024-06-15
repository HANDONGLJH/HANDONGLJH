#include "MyLinkedStack.h"
#include <iostream>

using namespace std;

Node::Node(int data) : data(data), next(nullptr) {}

MyLinkedStack::MyLinkedStack() : stacktop(nullptr) {}

MyLinkedStack::~MyLinkedStack() {
    clear();
}

bool MyLinkedStack::isEmpty() const {
    return stacktop == nullptr;
}

void MyLinkedStack::push(const int &elem) {
    Node* newNode = new Node(elem);
    newNode->next = stacktop;
    stacktop = newNode;
}

int MyLinkedStack::pop() {
    if (isEmpty()) {
        cout << "스택이 비어 있습니다." << endl;
        return -1; // 예외 처리를 위해 -1 리턴
    }
    Node* temp = stacktop;
    int data = temp->data;
    stacktop = stacktop->next;
    delete temp;
    return data; // 스택에서 제거된 요소를 리턴
}

int MyLinkedStack::peek() const {
    if (isEmpty()) {
        cout << "스택이 비어 있습니다." << endl;
        return -1; // 예외 처리를 위해 -1 리턴
    }
    return stacktop->data;
}

void MyLinkedStack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void MyLinkedStack::printAll() const {
    Node* current = stacktop;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int MyLinkedStack::getNodeCnt() const {
    int count = 0;
    Node* current = stacktop;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

Node* MyLinkedStack::getTop() const {
    return stacktop;
}