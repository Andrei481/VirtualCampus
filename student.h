#ifndef STUDENT_HEADER
#define STUDENT_HEADER


#include "user.h"

class Student : public User {
private:
    //std::vector<Course> courses;
    double course_average, annual_average;

public:
    using User::User;

    void checkGrades()
    {

    }

    double getCourseAverage()
    {
        return course_average;
    }

    double getAnnualAverage()
    {
        return annual_average;
    }
};

#endif