#include <iostream>
#include <vector>
#include <string>

class Student {

    // getter and setters
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
    std :: vector<std :: string> completedCourses;

};