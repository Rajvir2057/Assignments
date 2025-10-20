#include "Registrar.h"
// -- APIs students will call --
bool Registrar::enrollStudentInSection ( int studentId , int sectionId ) {
    Student* a = findStudent(studentId);
    Section* b = findSection(sectionId);
    Course* c = findCourseByCode(b->courseCode());
    std::vector <std::string> prereqs = c->prereqs();
    if(prerequisitesOk(*a,*c)){
        return b->enroll(studentId);
    }
    //O(n)
    return false;
} 
bool Registrar::dropStudentFromSection ( int studentId , int sectionId ) {
    return findSection(sectionId)->drop(studentId);
    //O(n)
} 

// -- adding to registries --
void Registrar::addStudent ( const Student & s ) {
    students_.push_back(s);
    //O(1)
} 
void Registrar::addCourse ( const Course & c ) {
    courses_.push_back(c);
    //O(1)
} 
void Registrar::addSection ( const Section & s ) {
    sections_.push_back(s);
    //O(1)
} 

// -- basic finders ( return nullptr if not found ) --
Student * Registrar::findStudent (int id ) {
    for (int i=0; i< students_.size(); i++){
        if (students_[i].id() == id){
            return &students_[i];
        }
    }
    return nullptr;
    //O(n)
} 
Section * Registrar::findSection (int sectionId ) {
    for (int i=0; i< sections_.size(); i++){
        if (sections_[i].sectionId() == sectionId){
            return &sections_[i];
        }
    }
    return nullptr;
    //O(n)
} 

Course * Registrar::findCourseByCode ( const std :: string & code ) {
    for (int i=0; i< students_.size(); i++){
        if (courses_[i].code() == code){
            return &courses_[i];
        }
    }
    return nullptr;
    //O(n)
} 

//Prints out the enrolled students in that section
void Registrar::studentPrint(int sectionId){
    Section* a = findSection(sectionId);

    a->studentList();
    //O(n)
} 

//Prints out the first position in waitlist
void Registrar::waitlistPrint(int sectionId){
    Section*a = findSection(sectionId);

    a->waitlistPrint();
    //O(1)
} 

// helper for prereq check
bool Registrar::prerequisitesOk (const Student& s , const Course & c ) const {
    std::vector <std::string> prereqs = c.prereqs();
    //Referenced from https://stackoverflow.com/questions/12702561/iterate-through-a-c-vector-using-a-for-loop
    if (prereqs.empty()){
        return true;
    }
    
    for(std::string i : prereqs){
            if (s.hasCompleted(i)){
                return true;
            }
    }
    return false;
    //O(n)
} 
