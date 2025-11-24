// SimpleQueue.h
#pragma once
#include "Node.h"

class SimpleQueue {
public:
    SimpleQueue();
    ~SimpleQueue();

    void enqueue(int x);  // add to back
    void dequeue();       // remove from front (assume non-empty internally)
    int front() const;    // read front (assume non-empty)
    bool empty() const;   // true if no nodes

private:
    Node* head_;          // front
    Node* tail_;          // back
};