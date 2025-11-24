// SimpleQueue.cpp
#include "SimpleQueue.h"
#include <cstddef> // for nullptr

SimpleQueue::SimpleQueue()
: head_(nullptr), tail_(nullptr) {}

SimpleQueue::~SimpleQueue() {
    while (!empty()) {
        dequeue();
    }
}

bool SimpleQueue::empty() const {
    return head_ == nullptr;
}

void SimpleQueue::enqueue(int x) {
    Node* n = new Node(x, nullptr);
    if (empty()) {
        head_ = tail_ = n;
    } else {
        tail_->next = n;
        tail_ = n;
    }
}

void SimpleQueue::dequeue() {
    if (empty()) {
        return; // defensive
    }
    Node* oldHead = head_;
    head_ = head_->next;
    if (head_ == nullptr) {
        tail_ = nullptr; // queue became empty
    }
    delete oldHead;
}

int SimpleQueue::front() const {
    // assume non-empty in assignment tests
    return head_->data;
}