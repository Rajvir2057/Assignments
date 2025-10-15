#ifndef _NODE
#define _NODE
struct Node{

    int data;
    Node* next;

    Node(int d, Node* n = nullptr); // ctor declared here.

    Node* getNext() const;
    void setNext(Node*);
};

#include "Node.cpp"
#endif 