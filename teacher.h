#ifndef TEACHER_HEADER
#define TEACHER_HEADER


#include <string>
#include "user.h"

class Teacher : public User {
private:
    std::string taught_course;

public:
    Teacher(std::string first_name, std::string last_name, uint16_t age, char gender, std::string username, std::string password, std::string phone_number, std::string course) : User(first_name, last_name, age, gender, username, password, phone_number)
    {
        this->taught_course = course;
    }

    // Getters

    std::string getUserInfo()
    {
        return User::getUserInfo() + " | Role: Teacher | Course: " + this->taught_course;
    }

    std::string getCourseName()
    {
        return this->taught_course;
    }
};

#endif