#include "MyStack.h"
#include <iostream>
using namespace std;

MyStack::MyStack(int size) {
    maxsize = size;
    top = -1;
    list = new int[maxsize];
}

MyStack::~MyStack() {
    delete[] list;
}

void MyStack::initialize() {
    top = -1;
}

bool MyStack::isEmpty() const {
    return top == -1;
}

bool MyStack::isFull() const {
    return top == maxsize - 1;
}

void MyStack::clear() {
    top = -1;
}

void MyStack::push(const int &elem) {
    if (isFull()) {
        cout << "스택이 가득 찼습니다." << endl;
    } else {
        list[++top] = elem;
    }
}

int MyStack::pop() {
    if (isEmpty()) {
        cout << "스택이 비어 있습니다." << endl;
        return -1;
    } else {
        return list[top--];
    }
}

void MyStack::print() const {
    if (isEmpty()) {
        cout << "스택이 비어 있습니다." << endl;
    } else {
        for (int i = 0; i <= top; ++i) {
            cout << list[i] << " ";
        }
        cout << endl;
    }
}