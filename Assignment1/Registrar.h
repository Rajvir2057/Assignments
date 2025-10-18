#ifndef REGISTRAR_
#define REGISTRAR_

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Course.h"
#include "Section.h"


class Registrar {

    public :
    // -- APIs students will call --
        bool enrollStudentInSection ( int studentId , int sectionId ) ; // TODO
        bool dropStudentFromSection ( int studentId , int sectionId ) ; // TODO

    // -- adding to registries --
        void addStudent ( const Student & s ) ; // TODO
        void addCourse ( const Course & c ) ; // TODO
        void addSection ( const Section & s ) ; // TODO

    // -- basic finders ( return nullptr if not found ) --
        Student * findStudent (int id ) ; // TODO
        Section * findSection (int sectionId ) ; // TODO
        Course * findCourseByCode ( const std :: string & code ) ; // TODO

    private :
// helper for prereq check
        bool prerequisitesOk ( const Student & s , const Course & c ) const ; // Todo

        std :: vector < Student > students_ ;
        std :: vector < Course > courses_ ;
        std :: vector < Section > sections_ ;

};
#include "Registrar.cpp"
#endif