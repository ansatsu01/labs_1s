#include "StudentAfter1session.h"

StudentAfter1stSession::StudentAfter1stSession(char* name, int course, int group, int* first_term_marks) : Student((char*) name, (int) course, (int) group) {


    for (int i = 0; i < 4; ++i) {
        this->first_term_marks[i] = first_term_marks[i];
    }
}

StudentAfter1stSession::StudentAfter1stSession(const StudentAfter1stSession &copy) : Student(copy.name, copy.course, copy.group){

    for(int i = 0; i < 4; ++i) {
        this->first_term_marks[i] = copy.first_term_marks[i];
    }

}

void StudentAfter1stSession::ChangeMark(int num_of_mark, int new_value) {

    first_term_marks[num_of_mark - 1] = new_value;
}

int StudentAfter1stSession::GetMark(int num_of_mark) {

    return first_term_marks[num_of_mark - 1];
}

double StudentAfter1stSession::AverageScore() {

    int sum = 0;

    for (int i = 0; i < 4; ++i) {

        sum+= first_term_marks[i];
    }

    return sum/4.0;

}

ostream &operator<<(ostream &out, const StudentAfter1stSession &s) {
    return out << "Student:" << s.name << " , " << "course: " << s.course << " , " <<
               "group: " << s.group << " , " << "ID: " << s.id << " , " <<
               "Marks after 1st session : "<< s.first_term_marks[0] << " " <<
               s.first_term_marks[1] << " " << s.first_term_marks[2] << " " <<
               s.first_term_marks[3] << " " << endl;

}


