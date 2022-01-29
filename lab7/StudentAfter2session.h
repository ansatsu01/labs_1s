#ifndef LAB7_STUDENTAFTER2SESSION_H
#define LAB7_STUDENTAFTER2SESSION_H

#include "Student.h"

class StudentAfter2ndSession : public StudentAfter1stSession {
public :
    int second_term_marks[5];

    StudentAfter2ndSession(char* name, int course, int group, int *first_term_marks, int *second_term_marks);


    StudentAfter2ndSession(const StudentAfter2ndSession &copy);

    void ChangeMark(int num_of_mark, int new_value);

    int GetMark(int number);

    double AverageScore() override;

    friend ostream &operator<<(ostream &out, const StudentAfter2ndSession &s);

};








#endif //LAB7_STUDENTAFTER2SESSION_H
