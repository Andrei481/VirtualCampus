#ifndef MENU_HEADER
#define MENU_HEADER


#include <string>
#include "student.h"
#include "teacher.h"
#include "db_utils.h"


// Function that accepts the password


bool check_password(std::string password_1, std::string password_2)
{
    if (password_1 == password_2)
        return true;
    std::cout << "Passwords do not match." << std::endl;
    return false;
}

bool check_role(char role)
{
    if (role == '1' || role == '2')
        return true;
    std::cout << "Invalid role." << std::endl;
    return false;
}

void register_user()
{
    std::string first_name, last_name, username, password, confirm_password, phone_number;
    uint16_t age;
    char gender;
    uint8_t role;

    std::cout << "First name: ";
    std::getline(std::cin >> std::ws, first_name);
    std::cout << "Last name: ";
    std::getline(std::cin >> std::ws, last_name);
    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "Gender (M/F): ";
    std::cin >> gender;
    std::cout << "Username: ";
    std::cin >> username;
    do {
        std::cout << "Password: ";
        std::cin >> password;
        std::cout << "Confirm password: ";
        std::cin >> confirm_password;
    } while (!check_password(password, confirm_password));
    std::cout << "Phone number: ";
    std::cin >> phone_number;
    do
    {
        std::cout << "Please choose your role (1/2):" << std::endl;
        std::cout << "1. Student" << std::endl << "2. Teacher" << std::endl;
        std::cin >> role;
    } while (!check_role(role));


    if (role == '1')
    {
        Student s(first_name, last_name, age, gender, username, password, phone_number);
        insert_into_database(s);
    }
    else if (role == '2')
    {
        std::string course;
        std::cout << "Taught course name:" << std::endl;
        std::cin >> course;
        Teacher t(first_name, last_name, age, gender, username, password, phone_number, course);
        insert_into_database(t);
    }

    std::cout << "Trying to establish connection to database..." << std::endl;
}

void running_session()
{
    bool b_running = true;
    uint8_t choice;
    while (b_running)
    {
        std::cout << "========================== Floppel University Virtual Campus =============================" << std::endl;
        std::cout << std::endl << std::endl << std::endl;
        std::cout << "Please choose an action:" << std::endl << std::endl;
        std::cout << "1. Login" << std::endl;
        std::cout << "2. Register" << std::endl;
        std::cout << "0. Exit" << std::endl << std::endl;

        std::cin >> choice;

        switch (choice)
        {
        case '0':
            std::cout << "Choice: Exit" << std::endl;
            b_running = 0;
            break;
        case '1':
            std::cout << "Choice : Login" << std::endl;
            break;
        case '2':
            std::cout << "Choice : Register" << std::endl;
            register_user();
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
        }
    }
}

#endif
