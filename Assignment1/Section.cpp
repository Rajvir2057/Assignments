#include <iostream>
#include "Section.h"

    // -- construction --

        Section ::  Section () {}
        Section :: Section (int sectionId , const std :: string & courseCode ){
        }

    // -- main behaviour --
        bool Section ::  isFull () const {} // TODO
        bool Section :: isEnrolled ( int studentId ) const {} // TODO
        bool Section :: enroll (int studentId ) {} // TODO ( array insert or waitlist )
        bool Section :: drop (int studentId ) {} // TODO ( remove + promote from waitlist )

    // -- minimal getters --
        int Section :: size () const {} // TODO
        int Section :: sectionId () const {} // TODO
        std :: string Section ::  courseCode () const {} // TODO

