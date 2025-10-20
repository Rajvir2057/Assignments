#include "Student.cpp"
#include <iostream>

int main(){
    Student a(10, "john", {"ball"});
    Student* c = &a;
    
    bool b = a.hasCompleted("balls");
}