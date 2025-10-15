#ifndef STUDENT_
#define STUDENT_

class Student{
    
    //cosntructors (might or might not be needed)
    Student();

    Student (const int& id, const std :: string& name, const std :: string& completed);

    //functions declarations for courses.
    void addCompleted(const std :: string& c);

    bool hascompleted(const std :: string& c );

    std :: vector<std :: string> completedCourses() const;


};
#include "Student.cpp"
#endif 
