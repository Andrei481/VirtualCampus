#ifndef USER_HEADER
#define USER_HEADER


#include <iostream>
#include <vector>
#include <string>

class User {
private:
    std::string first_name, last_name;
    uint16_t age;
    std::string gender;
    std::string phone_number;
    std::string username, password;

public:
    User(std::string first_name, std::string last_name, uint16_t age, char gender, std::string username, std::string password, std::string phone_number)
    {
        this->first_name = first_name;
        this->last_name = last_name;
        this->age = age;
        this->gender = gender;
        this->username = username;
        this->password = password;
        this->phone_number = phone_number;
    }

    std::string getUserInfo()
    {
        return "Name: " + first_name + " " + last_name + " | Age: " + std::to_string(age) + " | Gender: " + gender + " | Username: " + username + " | Phone number: " + phone_number;
    }

    // Getters

    std::string getfirstName()
    {
        return first_name;
    }

    std::string getLastName()
    {
        return last_name;
    }

    uint16_t getAge()
    {
        return age;
    }

    std::string getGender()
    {
        return gender;
    }

    std::string getUsername()
    {
        return username;
    }

    std::string getPassword()
    {
        return password;
    }

    std::string getPhoneNumber()
    {
        return phone_number;
    }

    // Setters

    /*void setName(std::string name)
    {
        this->name = name;
    }*/

    void setAge(uint16_t age)
    {
        this->age = age;
    }

    void setUsername(std::string username)
    {
        this->username = username;
    }
};

#endif
