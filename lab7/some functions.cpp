#include "some functions.h"

double AverageInGroupAfter1Session(vector<StudentAfter1stSession> students, int group){
    double avr;
    int num = 0;
    for(StudentAfter1stSession student : students) {
        if (student.GetGroup() == group) {
            avr += student.AverageScore();
            ++num;
        }
    }
    return avr / num;
}

double AverageInGroupAfter2Sessions(vector<StudentAfter2ndSession> students, int group){
    double avr;
    int num = 0;
    for(StudentAfter2ndSession student : students) {
        if (student.GetGroup() == group) {
            avr += student.AverageScore();
            ++num;
        }
    }
    return avr / num;
}


double AverageScoreForAllSt(const vector<Student*> &students){
    double sum = 0;
    double avr = 0;
    for(int i=0; i < students.size(); ++i){
        sum += students[i]->AverageScore();

    }
    avr = sum/ students.size();
    return avr;
}