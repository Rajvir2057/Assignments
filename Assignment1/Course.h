#ifndef COURSE_
#define COURSE_

#include <vector>
#include <string>

class Course{
    
    public:
    Course();
    Course(const std::string& code, const std::string& title, const std::vector<std::string>& newPrereq);
    //getters and setters
    std :: string code() const;
    void setCode(const std :: string& c);
    

    void addPrereq(const std :: string& c);
    std :: vector<std :: string> prereqs() const;


    void setTitle(const std :: string& t);
    std :: string title() const;

    private:

    std :: string code_;
    std :: string title_;
    std :: vector<std :: string> prereqs_;
};

#endif  
