#include "Student.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
    Student S;
    int selection =0;
    vector<Student>studentList;
    string name;
    int age;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.

            cout<<"Give the name of the new Student: ";
            cin>>name;
            cout<<"And the age of the new Student: ";
            cin>>age;

            studentList.push_back(Student(name, age));
            break;
        case 1:
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.

            for(auto& student : studentList)
            {
                student.printStudentInfo();
            }
            break;

        case 2:
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat

            sort(studentList.begin(), studentList.end(), [](Student& a, Student& b){
                return a.getName() < b.getName();
            });

            for(auto& student : studentList)
            {
                student.printStudentInfo();
            }
            break;

        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat

            sort(studentList.begin(), studentList.end(), [](Student& a, Student& b){
                return a.getAge() < b.getAge();
            });

            for(auto& student : studentList)
            {
                student.printStudentInfo();
            }
            break;
        case 4: {
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.

            string name_val;
            cout<<"Give a student name: ";
            cin>>name_val;

            auto it = find_if(studentList.begin(), studentList.end(), [&name_val](Student& student){
                return student.getName() == name_val;
            });

            if(it != studentList.end()){
                cout<<"Student found:\n";
                it->printStudentInfo();
            }else{
                cout<<"Student not found"<<endl;
            }
        }
            break;
        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }
   }while(selection < 5);
    return 0;
}
