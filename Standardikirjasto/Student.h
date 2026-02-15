#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student
{
public:
    Student(string name_val = "", int age_val = 0);
    void setAge(int);
    void setName(string);
    string getName();
    int getAge();
    void printStudentInfo();
private:
    string name;
    int age;
};

#endif // STUDENT_H
