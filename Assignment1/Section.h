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
        Section (int sectionId , const std :: string & courseCode, const int& cap_ ) ; // TODO

    // -- main behaviour --
        bool isFull () const ; // TODO
        bool isEnrolled ( int studentId ) const ; // TODO
        bool enroll (int studentId ) ; // TODO ( array insert or waitlist )
        bool drop (int studentId ) ; // TODO ( remove + promote from waitlist )

    // -- minimal getters --
        int size () const ; // TODO
        int sectionId () const ; // TODO
        std :: string courseCode () const ; // TODO

    // --Student getters --
        void studentList () const; //prints out the current students enrolled
        void waitlistPrint() const;
    private :
        int cap_;
        int sectionId_ = -1;
        std :: string courseCode_ ;
        int enrolled_ [ MAX_CAPACITY ];
        int count_ = 0;
        LinkedChain waitlist_ ; // stores int student IDs

};
#endif 