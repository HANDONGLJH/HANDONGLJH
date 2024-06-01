#ifndef MYSTACK_H
#define MYSTACK_H

class MyStack {
private:
    int maxsize;
    int top;
    int* list;

public:
    MyStack(int size = 10);
    ~MyStack();

    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    void clear();
    void push(const int &elem);
    int pop();
    void print() const;
};

#endif 