#ifndef STUDENT_
#define STUDENT_

#include <vector>
#include <string>

class Student {

    // getter and setters
    Student();
    Student (const int& id, const std :: string& name, const std :: string& completed);

    int id() const;
    void setid(int v);
    std :: string name() const;
    void setName(const std :: string& n);

    // course completion
    void addCompleted(const std :: string& c);
    bool hasCompleted (const std :: string& c);
    std :: vector<std :: string> completedCourses() const;

    // add meat to all the above.
    
    private:
    int id_;
    std :: string name_;
    std :: vector<std :: string> completedCourses_;

};

/*class Student{
    
    //cosntructors (might or might not be needed)
    Student();

    Student (const int& id, const std :: string& name, const std :: string& completed);

    //functions declarations for courses.
    void addCompleted(const std :: string& c);

    bool hascompleted(const std :: string& c );

    std :: vector<std :: string> completedCourses() const;


};*/
#include "Student.cpp"
#endif 
