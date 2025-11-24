// PriorityQueue.cpp
#include "PriorityQueue.h"
#include <utility> // for std::swap

PQItem::PQItem()
: id(-1), priority(0) {}

PQItem::PQItem(int idValue, int p)
: id(idValue), priority(p) {}

PriorityQueue::PriorityQueue()
: size_(0) {}

bool PriorityQueue::empty() const {
    return size_ == 0;
}

bool PriorityQueue::full() const {
    return size_ == MAX_SIZE;
}

void PriorityQueue::push(int id, int priority) {
    if (full()) {
        return;
    }
    int index = size_;
    heap_[index] = PQItem(id, priority);
    ++size_;
    heapifyUp(index);
}

void PriorityQueue::pop() {
    if (empty()) {
        return;
    }
    heap_[0] = heap_[size_ - 1];
    --size_;
    if (!empty()) {
        heapifyDown(0);
    }
}

PQItem PriorityQueue::top() const
{
    return heap_[0];
}

void PriorityQueue::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap_[index].priority > heap_[parent].priority) {
            std::swap(heap_[index], heap_[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void PriorityQueue::heapifyDown(int index) {
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size_ && heap_[left].priority > heap_[largest].priority)
        {
            largest = left;
        }
        if (right < size_ && heap_[right].priority > heap_[largest].priority)
        {
            largest = right;
        }

        if (largest != index) {
            std::swap(heap_[index], heap_[largest]);
            index = largest;
        } else {
            break;
        }
    }
}