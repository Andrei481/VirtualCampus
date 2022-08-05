#ifndef DB_HEADER
#define DB_HEADER


#include <stdlib.h>
#include <iostream>
#include "student.h"
#include "teacher.h"

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"
#include "mysql_driver.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>



sql::Driver* driver;
sql::Connection* con;


void connect_to_database()
{


    try
    {
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
    }
    catch (sql::SQLException e)
    {
        std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
        system("pause");
        exit(1);
    }
    con->setSchema("university_database");

}

void insert_into_database(Student student)
{
    sql::PreparedStatement* psInsert;
    sql::PreparedStatement* psInsertStudent;

    connect_to_database();

    try {

        // insert into Users DB

        psInsert = con->prepareStatement("INSERT INTO users_table (firstname, lastname, age, gender, username, password, phone) VALUES (?,?,?,?,?,?,?)");
        psInsert->setString(1, student.getfirstName());
        psInsert->setString(2, student.getLastName());
        psInsert->setUInt(3, student.getAge());
        psInsert->setString(4, student.getGender());
        psInsert->setString(5, student.getUsername());
        psInsert->setString(6, student.getPassword());
        psInsert->setString(7, student.getPhoneNumber());
        psInsert->execute();
    }
    catch (sql::SQLException e)
    {
        std::cout << "Error at insertion into user table. Error message: " << e.what() << std::endl;
        exit(2);
    }
    try {
        // insert into Students DB

        psInsertStudent = con->prepareStatement("INSERT INTO students_table (username, first_name, last_name) VALUES (?, ?, ?)");
        psInsertStudent->setString(1, student.getUsername());
        psInsertStudent->setString(2, student.getfirstName());
        psInsertStudent->setString(3, student.getLastName());
        psInsertStudent->execute();
    }
    catch (sql::SQLException e) {
        std::cout << "Error at insertion into students table. Error message: " << e.what() << std::endl;
        exit(3);
    }

    delete psInsertStudent;
    delete psInsert;
    delete con;
}

void insert_into_database(Teacher teacher)
{
    sql::PreparedStatement* psInsert;
    sql::PreparedStatement* psInsertTeacher;

    connect_to_database();

    try {

        // insert into Users DB

        psInsert = con->prepareStatement("INSERT INTO users_table (firstname, lastname, age, gender, username, password, phone) VALUES (?,?,?,?,?,?,?)");
        psInsert->setString(1, teacher.getfirstName());
        psInsert->setString(2, teacher.getLastName());
        psInsert->setUInt(3, teacher.getAge());
        psInsert->setString(4, teacher.getGender());
        psInsert->setString(5, teacher.getUsername());
        psInsert->setString(6, teacher.getPassword());
        psInsert->setString(7, teacher.getPhoneNumber());
        psInsert->execute();
    }
    catch (sql::SQLException e)
    {
        std::cout << "Error at insertion into user table. Error message: " << e.what() << std::endl;
        exit(2);
    }
    try {
        // insert into Teachers DB

        psInsertTeacher = con->prepareStatement("INSERT INTO teachers_table (username, first_name, last_name, course) VALUES (?, ?, ?, ?)");
        psInsertTeacher->setString(1, teacher.getUsername());
        psInsertTeacher->setString(2, teacher.getfirstName());
        psInsertTeacher->setString(3, teacher.getLastName());
        psInsertTeacher->setString(4, teacher.getCourseName());
        psInsertTeacher->execute();
    }
    catch (sql::SQLException e) {
        std::cout << "Error at insertion into teachers table. Error message: " << e.what() << std::endl;
        exit(4);
    }

    delete psInsertTeacher;
    delete psInsert;
    delete con;
}

#endif