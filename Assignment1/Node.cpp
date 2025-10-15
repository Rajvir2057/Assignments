#include "Node.h"

//constructor
Node :: Node(int d, Node* n) : data(d), next(n){}

Node* Node :: getNext() const {
    return next;
}
void Node :: setNext(Node* n) {
    next = n;
}

int Node :: getData() const{
    return data;
}
void Node :: setData(const int& i){
    data = i;
}