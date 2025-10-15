#ifndef _NODE
#define _NODE
struct Node{

    int data;
    Node* next;

    Node(int d, Node* n = nullptr); // ctor declared here.
};

#include "Node.cpp"
#endif 