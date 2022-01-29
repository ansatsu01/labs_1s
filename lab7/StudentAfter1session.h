#ifndef LAB7_STUDENTAFTER1SESSION_H
#define LAB7_STUDENTAFTER1SESSION_H

#include "Student.h"

class StudentAfter1stSession : public Student {

public:
    int first_term_marks[4];

    StudentAfter1stSession(char *name, int course, int group, int *first_term_marks);

    StudentAfter1stSession(const StudentAfter1stSession &copy);

    void ChangeMark(int num_of_mark, int new_value);

    int GetMark(int num_of_mark);

    double AverageScore() override;

    friend ostream &operator<<(ostream &out, const StudentAfter1stSession &s);

};








#endif //LAB7_STUDENTAFTER1SESSION_H
