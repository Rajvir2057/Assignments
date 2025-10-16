#include <iostream>
#include <ranges>
#include "Student.h"


//constructors
     Student :: Student() {}

     Student :: Student (const int& id, const std :: string& name, const std :: string& completed) {}

    int  Student :: id() const {
        return id_;
    }
    void  Student :: setid(int i) {
        id_ = i;
    }

    std :: string  Student :: name() const {
        return name_;
    }
    void  Student :: setName(const std :: string& n) {
        name_ = n;
    }

    // course completion
    void  Student :: addCompleted(const std :: string& c) {
        completedCourses_.push_back(c);
    }

    bool  Student :: hasCompleted (const std :: string& c) {

        return (std :: ranges :: find(completedCourses_, c) != completedCourses_.end());

        //find if is a function thats finds a container. 
        //std :: ranges :: find is the c++20 version in <ranges> library cited from cpp reference alogrithms for vectors from algorithms library.
        //if not we can use std :: find in <algorithm> library

        // Change C++ version in vscode: https://stackoverflow.com/a/68401689
    }

    std :: vector<std :: string> Student :: completedCourses() const {
         return completedCourses_;
    }

    // c is courses , i is for id and n is for name.