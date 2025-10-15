#ifndef _LINKEDCHAIN
#define _LINKEDCHAIN
#include "Node.h"

class LinkedChain {

    public :
        void push_back ( int x ) ; // TODO
        void pop_front () ; // TODO ( assume non - empty when called interanlly0
        int front () const ; // TODO ( assume non - empty )
        bool empty () const ; // TODO
        ~ LinkedChain () ; // TODO ( clean up nodes )


    private :
        Node * head_ = nullptr ;
        Node * tail_ = nullptr;

};


#include "Linkedchain.cpp"
#endif