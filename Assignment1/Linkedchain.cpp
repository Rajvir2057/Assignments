#include <iostream>
#include <vector>
#include <string>
#include "LinkedChain.h"

    //functions..

void LinkedChain::push_back (const int& x ){
    Node* n = new Node(x, nullptr); 
    if (!head_){
        head_ = n;
        tail_ = head_;
    }

    else{
        tail_ -> setNext(n);
        tail_ = n;
    }
    //O(1)
     
}
void LinkedChain::pop_front () { 
    Node* n = head_;
    head_ = head_ -> getNext();
    n -> setNext(nullptr);
    delete n;
    
    //O(1)

}
int LinkedChain::front () const { 
    Node* n = head_;
    return n->getData();
    //O(1)
}
bool LinkedChain::empty () const { 
    if (!head_){
        return true;
    }
    return false;
    //O(1)
}

//destructor
LinkedChain::~LinkedChain () {
    Node* cur = head_;
    while (cur != nullptr){
        pop_front();
        cur = head_;
    }
    //O(1)
}


