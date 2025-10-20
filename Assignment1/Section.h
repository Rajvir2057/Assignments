#ifndef SECTION_
#define SECTION_

#include <vector>
#include <string>
#include <iostream> 
#include "Linkedchain.h"

class Section {

    public :
        static const int MAX_CAPACITY = 50;

    // -- construction --

        Section () ; // TODO
        Section (int sectionId , const std :: string & courseCode, const int& cap_ ) ; 

    // -- main behaviour --
        bool isFull () const ; 
        bool isEnrolled ( int studentId ) const ; 
        bool enroll (int studentId ) ;
        bool drop (int studentId ) ; 

    // -- minimal getters --
        int size () const ; 
        int sectionId () const ; 
        std :: string courseCode () const ; 
    // --Student getters --
        void studentList () const; //prints out the current students enrolled
        void waitlistPrint() const; //prints out the first waitlist spot
    private :
        int cap_; //capacity that limits the amount of usable array elements
        int sectionId_ = -1;
        std :: string courseCode_ ;
        int enrolled_ [ MAX_CAPACITY ];
        int count_ = 0;
        LinkedChain waitlist_ ; // stores int student IDs

};
#endif 