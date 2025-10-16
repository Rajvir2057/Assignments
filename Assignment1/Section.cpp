#include <iostream>
#include "Section.h"
#include <ranges>

    // -- construction --

        Section ::  Section () {}
        Section :: Section (int sectionId , const std :: string & courseCode ) : sectionId_(sectionId) , courseCode_(courseCode){}

    // -- main behaviour --
        bool Section ::  isFull () const {
            return (size() == MAX_CAPACITY);
        } 

        bool Section :: isEnrolled ( int studentId ) const {
            for(int i = 0 ; i < MAX_CAPACITY; i++){
                if(studentId == enrolled_[i]){
                    return true;
                }
            }return false;
        } 

        bool Section :: enroll (int studentId ) {
            if (isEnrolled(studentId)){
                return false;
            }
            if (true /*TODO replace with prereq pass*/) {
                if(! isFull()){
                    
                    enrolled_[size()] = studentId;
                    count_++;
                    return true;
                }else{
                    waitlist_.push_back(studentId);
                    return true;
                }
            }
        } 

        bool Section :: drop (int studentId ) {
            if(isEnrolled(studentId)){
                enrolled_[size()-1] = 0;
                count_ -- ;
                
                if(!waitlist_.empty()){
                    enrolled_[size()] = waitlist_.front();
                    waitlist_.pop_front();
                    count_ ++;
                    return true;
                }
            } else {
                return false;
            }
        } 

    // -- minimal getters --
        int Section :: size () const {
            return count_;
        } 

        int Section :: sectionId () const {
                return sectionId_;
        } 
        std :: string Section ::  courseCode () const {
            return courseCode_;
        }


