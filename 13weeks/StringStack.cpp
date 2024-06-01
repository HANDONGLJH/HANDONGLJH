#include "StringStack.h"
#include <iostream>
using namespace std;

StringStack::StringStack(int size) {
    list.reserve(size);
}

StringStack::~StringStack() {}

void StringStack::initialize() {
    list.clear();
}

bool StringStack::isEmpty() const {
    return list.empty();
}

bool StringStack::isFull() const {
    return list.size() == list.capacity();
}

void StringStack::clear() {
    list.clear();
}

void StringStack::push(const std::string &elem) {
    if (isFull()) {
        cout << "스택이 가득 찼습니다." << endl;
    } else {
        list.push_back(elem);
    }
}

std::string StringStack::pop() {
    if (isEmpty()) {
        cout << "스택이 비어 있습니다." << endl;
        return "";
    } else {
        std::string top = list.back();
        list.pop_back();
        return top;
    }
}

void StringStack::print() const {
    if (isEmpty()) {
        cout << "스택이 비어 있습니다." << endl;
    } else {
        for (const auto &elem : list) {
            cout << elem << " ";
        }
        cout << endl;
    }
}