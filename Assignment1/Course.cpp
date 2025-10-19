#include <iostream>
#include <vector>
#include "Course.h"

std :: string Course::code() const{
    return code_;
}
void Course::setCode(const std :: string& c){
    code_ = c;
} 

void Course::addPrereq(const std :: string& c){
    prereqs_.push_back(c);
}
std :: vector<std :: string> Course::prereqs() const{
    return prereqs_;
}

void Course::setTitle(const std :: string& t){
    title_ = t;
}
std :: string Course::title() const{
    return title_;
}
