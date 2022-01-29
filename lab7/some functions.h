#ifndef LAB7_SOME_FUNCTIONS_H
#define LAB7_SOME_FUNCTIONS_H

#include "StudentAfter1session.h"
#include "StudentAfter2session.h"
#include <vector>

double AverageInGroupAfter1Session(vector<StudentAfter1stSession> students, int group);
double AverageInGroupAfter2Sessions(vector<StudentAfter2ndSession> students, int group);
double AverageScoreForAllSt(const vector<Student*> &students);



#endif //LAB7_SOME_FUNCTIONS_H
