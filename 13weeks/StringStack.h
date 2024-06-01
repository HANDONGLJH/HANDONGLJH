#ifndef STRINGSTACK_H
#define STRINGSTACK_H

#include <string>
#include <vector>

class StringStack {
private:
    std::vector<std::string> list;

public:
    StringStack(int size = 10);
    ~StringStack();

    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    void clear();
    void push(const std::string &elem);
    std::string pop();
    void print() const;
};

#endif 