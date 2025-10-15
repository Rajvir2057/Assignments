#ifndef _NODE
#define _NODE
struct Node{
    private:
        int data;
        Node* next;

    public:
        Node(int d, Node* n = nullptr); // ctor declared here.

        Node* getNext() const;
        void setNext(Node* n);

        int getData() const;
        void setData(const int& i);
};

#include "Node.cpp"
#endif 