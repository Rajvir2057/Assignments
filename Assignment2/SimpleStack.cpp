// SimpleStack.cpp
#include "SimpleStack.h"

SimpleStack::SimpleStack()
: topIndex_(-1) {}

bool SimpleStack::empty() const
{
    return topIndex_ == -1;
}

bool SimpleStack::full() const
{
    return topIndex_ == MAX_SIZE - 1;
}

void SimpleStack::push(int x) {
    if (full()) {
        return;
    }
    ++topIndex_;
    data_[topIndex_] = x;
}

void SimpleStack::pop() {
    if (empty()) {
        return;
    }
    --topIndex_;
}

int SimpleStack::top() const
{
    return data_[topIndex_];
}