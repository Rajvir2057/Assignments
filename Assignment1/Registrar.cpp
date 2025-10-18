#include "Registrar.h"
// -- APIs students will call --
bool Registrar::enrollStudentInSection ( int studentId , int sectionId ) {
    Student* a = findStudent(studentId);
    Section* b = findSection(sectionId);
    Course* c = findCourseByCode(b->courseCode());
    std::vector <std::string> prereqs = c->prereqs();
    int i =0;
    if (a, b, c){
        if(prerequisitesOk(*a,*c)){
            return b->enroll(studentId);
        }
    }
    
    return false;
} 
bool Registrar::dropStudentFromSection ( int studentId , int sectionId ) {
    return findSection(sectionId)->drop(studentId);
} // TODO

// -- adding to registries --
void Registrar::addStudent ( const Student & s ) {
    students_.push_back(s);
} 
void Registrar::addCourse ( const Course & c ) {
    courses_.push_back(c);
} 
void Registrar::addSection ( const Section & s ) {
    sections_.push_back(s);
} 

// -- basic finders ( return nullptr if not found ) --
Student * Registrar::findStudent (int id ) {
    for (int i=0; i< students_.size(); i++){
        if (students_[i].id() == id){
            return &students_[i];
        }
    }
    return nullptr;
} 
Section * Registrar::findSection (int sectionId ) {
    for (int i=0; i< sections_.size(); i++){
        if (sections_[i].sectionId() == sectionId){
            return &sections_[i];
        }
    }
    return nullptr;
} 
Course * Registrar::findCourseByCode ( const std :: string & code ) {
    for (int i=0; i< students_.size(); i++){
        if (courses_[i].code() == code){
            return &courses_[i];
        }
    }
    return nullptr;
} 

// helper for prereq check
bool Registrar::prerequisitesOk ( const Student & s , const Course & c ) const {
    std::vector <std::string> prereqs = c.prereqs();
    int i=0;
    while(i<prereqs.size()){
            if (s.hasCompleted(prereqs[i])){
                return false;
            }
            i++;
    }
    return true;
} 
