#ifndef STUDENT_
#define STUDENT_

class Student{
    
    //just added this not sure if needed 
    Student();

    Student (const int )
    //functions declarations for courses.
    void addCompleted(const std :: string& c);

    bool hascompleted(const std :: string& c );

    std :: vector<std :: string> completedCourses() const;

    //function declarations to add student id and name.
    
    void addStudentinfo(const int id, std :: string Name);

};
#include "Student.cpp"
#endif 
