// PriorityQueue.h
#pragma once

class PQItem {
public:
    int id;           // we will use this for order ID
    int priority;     // larger = more urgent

    PQItem();
    PQItem(int idValue, int p);
};

class PriorityQueue {
public:
    static const int MAX_SIZE = 100;

    PriorityQueue();

    bool empty() const;
    bool full() const;

    void push(int id, int priority); // insert new item
    void pop();                      // remove most urgent (assume non-empty)
    PQItem top() const;              // read most urgent (assume non-empty)

private:
    PQItem heap_[MAX_SIZE];          // heap [0..size_-1]
    int size_;                       // number of elements

    void heapifyUp(int index);
    void heapifyDown(int index);
};