// Node.h
#pragma once

class Node {
public:
    int data;            // stores an int (we use it for order IDs)
    Node* next;

    Node(int d, Node* n = nullptr);
};