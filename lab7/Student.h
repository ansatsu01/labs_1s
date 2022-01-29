
#ifndef LAB7_STUDENT_H
#define LAB7_STUDENT_H

#include <string>
#include <iostream>

using namespace std;

class Student {
protected:
    int credit_card_number;
    int id;
    char* name;
    int course;
    int group;
public:

    static int Count;
    Student(char* name, int course, int group);

    Student(const Student &copy);

  ~Student();

    void SetName(char* name_of_student);

    void SetCourse(int number_of_course);

    void SetGroup(int number_of_group);

    char* GetName();

    int GetCourse();

    int GetGroup();

    int GetId();

    int GetCreditCardNumber();

   virtual double AverageScore();


    friend ostream &operator<<(ostream &out, const Student &s);


};







#endif //LAB7_STUDENT_H
