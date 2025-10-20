#include "Registrar.h"
#include <iostream>
#include <vector>
int main(){
    //Initialization
    Student a(10, "Alice Johnson", {});
    Student b(20, "Brian Smith", {});
    Student c(30, "Carlos Nguyen", {});
    Student d(40, "Dana Lee", {});
    Student e(50, "Ethan Patel", {});
    Student f(60, "Farah Brown", {});

    Course oneH("CSC100", "CSC", {} );
    Course twoH("CSC200", "CSC", {"CSC100"});
    Course threeH("CSC300", "CSC", {"CSC200"});

    Section one(1001, "CSC100", 2);
    Section two(2001, "CSC200", 2);
    Section three(3001, "CSC300", 3);

    Registrar reg;
    reg.addStudent(a);
    reg.addStudent(b);
    reg.addStudent(c);
    reg.addStudent(d);
    reg.addStudent(e);
    reg.addStudent(f);

    reg.addCourse(oneH);
    reg.addCourse(twoH);
    reg.addCourse(threeH);

    reg.addSection(one);
    reg.addSection(two);
    reg.addSection(three);

    //TESTS

    //T1
    std::cout<<"T1: Enrolling Students in section :";
    std::cout<<"\nEnroll Alice Johnson in 1001 (0= fail, 1=success): ";
    std::cout<<reg.enrollStudentInSection(10,1001);
    reg.studentPrint(1001);
    reg.waitlistPrint(1001);

    std::cout<<"\nEnroll Brian Smith in 1001 (0= fail, 1=success): ";
    std::cout<<reg.enrollStudentInSection(20,1001);
    reg.studentPrint(1001);
    reg.waitlistPrint(1001);

    std::cout<<"\nEnroll Carlos Nguyen in 1001 (0= fail, 1=success): ";
    std::cout<<reg.enrollStudentInSection(30,1001);
    reg.studentPrint(1001);
    reg.waitlistPrint(1001);

    //T2
    std::cout<<"\nT2: Promotion\nDrop Alice Johnson from 1001 (0= fail, 1=success): ";
    std::cout<<reg.dropStudentFromSection(10,1001);
    reg.studentPrint(1001);
    reg.waitlistPrint(1001);

    //T3
    std::cout<<"\nT3: Prerequisite\nEnroll Dana Lee in 2001 (0= fail, 1=success): ";
    std::cout<<reg.enrollStudentInSection(40,2001);
    reg.studentPrint(2001);
    reg.waitlistPrint(2001);
    std::cout<<"\nAdding CSC100 to Dana Lee\n";
    Student* Dana = reg.findStudent(40);
    Dana->addCompleted("CSC100");
    std::cout<<"Retrying ; Enroll Dana Lee in 2001 (0= fail, 1=success): ";
    std::cout<<reg.enrollStudentInSection(40,2001);
    reg.studentPrint(2001);
    reg.waitlistPrint(2001);

    //T4
    std::cout<<"\nT4: Drop Missing\nDrop Alice Johnson from 2001 (0= fail, 1=success): ";
    std::cout<<reg.dropStudentFromSection(10,2001);
    reg.studentPrint(1001);
    reg.studentPrint(2001);

    //T5
    std::cout<<"\n\nT5: No duplicates\nEnroll Dana Lee in 2001 (0= fail, 1=success): ";
    std::cout<<reg.enrollStudentInSection(40,2001);
    reg.studentPrint(2001);
    reg.waitlistPrint(2001);



}
