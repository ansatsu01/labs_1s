#include "gtest/gtest.h"
#include "Student.h"
#include "StudentAfter1session.h"
#include "StudentAfter2session.h"
#include "some functions.h"


TEST (GetMethods, getcourse) {

    Student a("boba", 1, 4);
    ASSERT_EQ(a.GetCourse(), 1);
}

TEST (GetMethods, getgroup) {

    Student a("boba", 1, 4);
    ASSERT_EQ(a.GetGroup(), 4);
}

TEST(GetMethods, getname){

    Student biba("boba", 1, 4);
    ASSERT_EQ("boba", biba.GetName());
}

TEST(GetMethods, getmark){

    int marks[4] = {5, 8, 7, 10};

    StudentAfter1stSession biba ("boba", 1, 4, marks);

    ASSERT_EQ(biba.GetMark(3), 7);

}


TEST(AverageAfter1s, check_for_7896) {

    int marks[4] = {7, 8, 9, 6};
    StudentAfter1stSession biba("boba", 1, 4, marks);
    ASSERT_DOUBLE_EQ(7.5, biba.AverageScore());
}

TEST(AverageAfter2s, check_for_marks_789645768) {

    int marks1s[4] = {7, 8, 9, 6};
    int marks2s[5] = {4, 5, 7, 6, 8};
    StudentAfter2ndSession biba("boba", 1, 4, marks1s, marks2s);
    ASSERT_NEAR(6.666, biba.AverageScore(), 0.001);
}

TEST(AverageAfter2s, check_for_marks_108999910108) {

    int marks1s[4] = {10, 8, 9, 9};
    int marks2s[5] = {9, 9, 10, 10, 8};
    StudentAfter2ndSession biba("boba", 1, 4, marks1s, marks2s);
    ASSERT_NEAR(9.111, biba.AverageScore(), 0.001);
}

TEST(AverageInGroupAfter1s, test_without_sorting_bygroups) {

    int marks1[4] = {2, 9, 6, 4};
    StudentAfter1stSession a("biba", 1, 4, marks1);

    int marks2[4] = {8, 9, 7,5};
    StudentAfter1stSession b("biba", 1, 4, marks2);

    vector<StudentAfter1stSession> students_after_1s;

    students_after_1s.push_back(a);
    students_after_1s.push_back(b);

    ASSERT_NEAR(AverageInGroupAfter1Session(students_after_1s, 4), 6.25, 0.001);

}

TEST(AverageInGroupAfter1s, test_with_sorting_bygroups) {

    int marks1[4] = {2, 9, 10, 4};
    StudentAfter1stSession s1("biba", 1, 4, marks1);

    int marks2[4] = {8, 9, 7,7};
    StudentAfter1stSession s2("boba", 1, 4, marks2);

    int marks3[4] = {8, 5, 7,3};
StudentAfter1stSession s3 ("buba", 1, 1, marks3);

    vector<StudentAfter1stSession> students_after_1s;

    students_after_1s.push_back(s1);
    students_after_1s.push_back(s2);
    students_after_1s.push_back(s3);

    ASSERT_NEAR(AverageInGroupAfter1Session(students_after_1s, 4), 7, 0.001);

}


TEST(AverageInGroupAfter2s, test1){

    int marks1s_1[4] = {4, 5, 6, 7};
    int marks2s_1[5] = {7, 8, 4, 6, 9};

    StudentAfter2ndSession st1("biba", 1, 4, marks1s_1, marks2s_1);

    int marks1s_2[4] = {9, 5, 8, 7};
    int marks2s_2[5] = {5, 8, 10, 6, 9};

    StudentAfter2ndSession st2("biba", 1, 4, marks1s_2, marks2s_2);

    int marks1s_3[4] = {2, 5, 8, 7};
    int marks2s_3[5] = {7, 8, 5, 10, 9};

    StudentAfter2ndSession st3("biba", 1, 4, marks1s_3, marks2s_3);

    vector<StudentAfter2ndSession> students_after_2s;

    students_after_2s.push_back(st1);
    students_after_2s.push_back(st2);
    students_after_2s.push_back(st3);

    ASSERT_NEAR(AverageInGroupAfter2Sessions(students_after_2s, 4), 6.815, 0.001);

}

TEST(AverageInGroupAfter2s, test_with_using_copying_constructor){

    int marks1s_1[4] = {4, 5, 6, 7};
    int marks2s_1[5] = {7, 8, 4, 6, 9};

    StudentAfter2ndSession st1("biba", 1, 4, marks1s_1, marks2s_1);

    int marks1s_2[4] = {9, 5, 8, 7};
    int marks2s_2[5] = {5, 8, 10, 6, 9};

    StudentAfter2ndSession st2("biba", 1, 4, marks1s_2, marks2s_2);

    int marks1s_3[4] = {2, 5, 8, 7};
    int marks2s_3[5] = {7, 8, 5, 10, 9};

    StudentAfter2ndSession st3("biba", 1, 4, marks1s_3, marks2s_3);

    StudentAfter2ndSession st4(st3);

    vector<StudentAfter2ndSession> students_after_2s;

    students_after_2s.push_back(st1);
    students_after_2s.push_back(st2);
    students_after_2s.push_back(st3);
    students_after_2s.push_back(st4);


    ASSERT_NEAR(AverageInGroupAfter2Sessions(students_after_2s, 4), 6.8, 0.01);

}

TEST(SetMethods, set_group){

    Student biba("boba", 1, 4);
biba.SetGroup(1);
    ASSERT_EQ(biba.GetGroup(), 1);
}

TEST(SetMethods, set_course){

    Student biba("boba", 1, 4);
    biba.SetCourse(2);
    ASSERT_EQ(biba.GetCourse(), 2);
}


TEST(SetMethods, set_name){

    Student biba("boba", 1, 4);
    char* new_name = "beba";
    biba.SetName(new_name);
    ASSERT_EQ(biba.GetName(), new_name);
}


TEST(change_mark_methods, test1){

    int marks1[4] = {2, 9, 6, 4};
    StudentAfter1stSession biba("biba", 1, 4, marks1);
    biba.ChangeMark(1, 9);
    ASSERT_EQ(biba.GetMark(1), 9);
}

TEST(change_mark_methods, test2){

    int marks1s_1[4] = {4, 5, 6, 7};
    int marks2s_1[5] = {7, 8, 4, 6, 9};

    StudentAfter2ndSession st1("biba", 1, 4, marks1s_1, marks2s_1);

    st1.ChangeMark(3, 5);
    ASSERT_EQ(st1.GetMark(3), 5);

}