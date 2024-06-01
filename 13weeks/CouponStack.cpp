#include "CouponStack.h"
#include <iostream>

using namespace std;

CouponStack::CouponStack(int size) : maxsize(size), top(-1) {
    list = new Coupon[maxsize];
}

CouponStack::~CouponStack() {
    delete[] list;
}

void CouponStack::initialize() {
    top = -1;
}

bool CouponStack::isEmpty() const {
    return top == -1;
}

bool CouponStack::isFull() const {
    return top == maxsize - 1;
}

void CouponStack::push(const Coupon &coupon) {
    if (isFull()) {
        cout << "스택이 가득 찼습니다." << endl;
    } else {
        list[++top] = coupon;
    }
}

Coupon *CouponStack::pop() {
    if (isEmpty()) {
        cout << "스택이 비어 있습니다." << endl;
        return nullptr;
    } else {
        return &list[top--];
    }
}

void CouponStack::print() const {
    if (isEmpty()) {
        cout << "스택이 비어 있습니다." << endl;
    } else {
        for (int i = 0; i <= top; ++i) {
            cout << "등수: " << list[i].rank << ", 상품명: " << list[i].reward
                 << endl;
        }
    }
}

void CouponStack::rprint() {
    while (!isEmpty()) {
        Coupon *coupon = pop();
        if (coupon != nullptr) {
            cout << "등수: " << coupon->rank << ", 상품명: " << coupon->reward
                 << endl;
        }
    }
}