#include "Linkedchain.cpp"
#include <iostream>
int main(){
    std::cout<<"a";
    LinkedChain n;
    n.push_back(1);
    std::cout<<n.front();
    n.push_back(3);
    n.pop_front();
    std::cout<<n.front();
    
}