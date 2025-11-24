// SimpleStack.h
#pragma once

class SimpleStack {
public:
    static const int MAX_SIZE = 100;

    SimpleStack();

    bool empty() const;
    bool full() const;

    void push(int x); // assume not full in tests
    void pop();       // assume non-empty in tests

    int top() const;  // assume non-empty in tests

private:
    int data_[MAX_SIZE];
    int topIndex_;    // index of top element, -1 when empty
};