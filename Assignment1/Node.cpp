#include "Node.h"

//constructor
Node :: Node(int d, Node* n) : data(d), next(n){}

Node* Node :: getNext() const {
    return next;
    //O(1)
}
void Node :: setNext(Node* n) {
    next = n;
    //O(1)
}

int Node :: getData() const{
    return data;
    //O(1)
}
void Node :: setData(const int& i){
    data = i;
    //O(1)
}