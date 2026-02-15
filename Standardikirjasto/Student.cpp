#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(string name_val, int age_val)
{
    cout<<"Student constructor.\n";
    setName(name_val);
    setAge(age_val);
}

void Student::setAge(int s)
{
    age = s;
}

void Student::setName(string s)
{
    name = s;
}

string Student::getName()
{
    string s = name;
    return s;
}

int Student::getAge()
{
    int s = age;
    return s;
}

void Student::printStudentInfo()
{
    cout<<getName()<<" "<<getAge()<<endl;
}
