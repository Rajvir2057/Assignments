#include "Section.h"
#include <ranges>

    // -- construction --

        Section ::  Section () {}
        Section :: Section (int sectionId , const std :: string & courseCode, const int& cap) : sectionId_(sectionId) , courseCode_(courseCode), cap_(cap){}

    // -- main behaviour --
        bool Section ::  isFull () const {
            return (size() == cap_||size()==MAX_CAPACITY);
            //O(1)
        } 

        bool Section :: isEnrolled ( int studentId ) const {
            for(int i = 0 ; i < MAX_CAPACITY; i++){
                if(studentId == enrolled_[i]){
                    return true;
                }
            }return false;
            //O(n)
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
            //O(n)
        } 

        bool Section :: drop (int studentId ) {
            if(isEnrolled(studentId)){
                int i =0;
                int j=0;
                while(i<size()){
                    if(studentId == enrolled_[i]){
                        enrolled_[i]=0;
                        j=i;
                    }
                    i++;
                }
                count_ -- ;
                
                if(!waitlist_.empty()){
                    enrolled_[j] = waitlist_.front();
                    waitlist_.pop_front();
                    count_ ++;
                    return true;
                }
                return true;
            }
            return false;
            //O(n)
        } 

    // -- minimal getters --
        int Section :: size () const {
            return count_;
            //O(1)
        } 

        int Section :: sectionId () const {
                return sectionId_;
                //O(1)
        } 
        std :: string Section ::  courseCode () const {
            return courseCode_;
            //O(1)
        }
        void Section::studentList () const{
            std::cout<<"\nCurrent students in "<< sectionId() << ": ";
        
            std::cout<<"{";
            for (int i=0; i<size(); i++){
                std::cout<<" ";
                std::cout<<enrolled_[i];
                std::cout<<" ";
            }
            std::cout<<"}";
            //O(n)
        }
        void Section::waitlistPrint() const{
            if(!waitlist_.empty()){
                std::cout<<"\nWaitlist : {"<<waitlist_.front()<<"}\n";
            }
            else{
                std::cout<<"\nWaitlist : {}\n";
            }
            //O(1)
            
        }


