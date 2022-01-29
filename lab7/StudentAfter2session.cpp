#include "StudentAfter1session.h"
#include "StudentAfter2session.h"

StudentAfter2ndSession::StudentAfter2ndSession(char* name, int course, int group, int* first_term_marks, int* second_term_marks) :
StudentAfter1stSession((char*) name, (int) course, (int) group, (int*) first_term_marks) {

for (int i = 0; i < 5; ++i) {
this->second_term_marks[i] = second_term_marks[i];
}
}

StudentAfter2ndSession::StudentAfter2ndSession(const StudentAfter2ndSession &copy) : StudentAfter1stSession(copy) {

    for (int i = 0; i < 5; ++i) {
        this->second_term_marks[i] = copy.second_term_marks[i];
    }

}

void StudentAfter2ndSession::ChangeMark (int num_of_mark, int new_value) {

    second_term_marks[num_of_mark - 1] = new_value;
}

int StudentAfter2ndSession::GetMark(int number){

    return  second_term_marks[number - 1];
}

double StudentAfter2ndSession::AverageScore() {

    int sum = 0;
    for (int i = 0; i < 5; ++i) {

        sum+= second_term_marks[i];
    }
    for (int i = 0; i < 4; ++i) {

        sum+= first_term_marks[i];
    }

    return sum/9.0;

}

ostream &operator<<(ostream &out, const StudentAfter2ndSession &s) {
    return out << "Student:" << s.name << " , " << "course: " << s.course << " , " <<
               "group: " << s.group << " , " << "ID: " << s.id << " , " <<
               "Marks after 2 sessions : "<< s.first_term_marks[0] << " " <<
               s.first_term_marks[1] << " " << s.first_term_marks[2] << " " <<
               s.first_term_marks[3] << " " << s.second_term_marks[0] << " " <<
               s.second_term_marks[1] << " " << s.second_term_marks[2] << " " <<
               s.second_term_marks[3] << " " << s.second_term_marks[4] << endl;

}