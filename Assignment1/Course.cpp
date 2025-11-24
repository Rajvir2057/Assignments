#include <iostream>
#include <vector>
#include <string>
#include "Course.h"

Course::Course(): code_("0"),title_(""),prereqs_(){
    //O(1)
}
Course::Course(const std::string& code, const std::string& title, const std::vector<std::string>& newPrereq) : code_(code),title_(title),prereqs_(newPrereq){
    //O(1)
}
std :: string Course::code() const{
    return code_;
    //O(1)
}
void Course::setCode(const std :: string& c){
    code_ = c;
    //O(1)
} 

void Course::addPrereq(const std :: string& c){
    prereqs_.push_back(c);
    //O(1)
}
std :: vector<std :: string> Course::prereqs() const{
    return prereqs_;
    //O(1)
}

void Course::setTitle(const std :: string& t){
    title_ = t;
    //O(1)
}
std :: string Course::title() const{
    return title_;
    //O(1)
}
