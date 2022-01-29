#include "Student.h"

int Student::Count = 0;

Student::Student(char *name, int course, int group) {

this->name = name;
this->course= course;
this->group = group;
Count ++;
id = Count;
}

Student::Student(const Student &copy) {

    this->name = copy.name;
    this->course = copy.course;
    this->group = copy.group;
    this->credit_card_number = copy.credit_card_number;
    this->id = id + 1;
}

Student::~Student() {
    delete[] name;
}

void Student::SetName(char* name_of_student){

    name = name_of_student;
}


void Student::SetCourse (int number_of_course){

    course = number_of_course;
}

void Student::SetGroup (int number_of_group) {

    group = number_of_group;
}

char* Student::GetName(){
    return name;
}

int Student::GetCourse () {
    return course;
}

int Student::GetGroup(){
    return group;
}

int Student::GetId(){

    return id;
}

int Student::GetCreditCardNumber(){
    return credit_card_number;
}


double Student::AverageScore() {
    return  0;
}


ostream &operator<<(ostream &out, const Student &s) {
    return out  <<"Student:" << s.name << " , " << "course: " << s.course << " , " <<
                "group: " << s.group << " , " << "ID: " << s.id << endl;
}
