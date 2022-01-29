#include "gtest/gtest.h"
#include "proper_fraction.h"

TEST(getMethods, test1)
{
    proper_fraction p(3,5);
    ASSERT_EQ(p.get_fraction_numenator(),3);
    ASSERT_EQ(p.get_fraction_denominator(), 5);

}

TEST(getMethods, test2)
{
    proper_fraction p(-3,5);
    ASSERT_EQ(p.get_fraction_numenator(),-3);
    ASSERT_EQ(p.get_fraction_denominator(), 5);

}

TEST (CopyConst, test1)
{
    proper_fraction p1 (2,5);
    proper_fraction p2(p1);

    ASSERT_EQ(p2.get_fraction_numenator(), 2);
    ASSERT_EQ(p2.get_fraction_denominator(), 5);

}


TEST(CutFraction, test1)
{
    proper_fraction p(3,9);
    p.cut_fraction();
    ASSERT_EQ(p.get_fraction_numenator(),1);
    ASSERT_EQ(p.get_fraction_denominator(), 3);

}

TEST(CutFraction, test2)
{
    proper_fraction p(-5,25);
    p.cut_fraction();
    ASSERT_EQ(p.get_fraction_numenator(),-1);
    ASSERT_EQ(p.get_fraction_denominator(), 5);

}

TEST(sum, test1)
{
    proper_fraction p1(1,3);
    proper_fraction p2(1,3);
    p1.fraction_sum(p2);

    ASSERT_EQ(p1.get_fraction_numenator(),2);
    ASSERT_EQ(p1.get_fraction_denominator(), 3);

}

TEST(sum, test2)
{
    proper_fraction p1(1,9);
    proper_fraction p2(2,9);
    p1.fraction_sum(p2);

    ASSERT_EQ(p1.get_fraction_numenator(),1);
    ASSERT_EQ(p1.get_fraction_denominator(), 3);

}


TEST(sum, test3)
{
    proper_fraction p1(-1,3);
    proper_fraction p2(2,3);
    p1.fraction_sum(p2);

    ASSERT_EQ(p1.get_fraction_numenator(),1);
    ASSERT_EQ(p1.get_fraction_denominator(), 3);

}

TEST(sum, test4)
{
    proper_fraction p1(1,3);
    proper_fraction p2(2,7);
    p1.fraction_sum(p2);

    ASSERT_EQ(p1.get_fraction_numenator(),13);
    ASSERT_EQ(p1.get_fraction_denominator(), 21);

}

TEST(sumWithInt, test1)
{
    proper_fraction p1(-1,3);
    p1.fraction_sum(1);

    ASSERT_EQ(p1.get_fraction_numenator(),2);
    ASSERT_EQ(p1.get_fraction_denominator(), 3);

}

TEST(sumWithInt, test2)
{
    proper_fraction p1(1,2);
    p1.fraction_sum(1);

    ASSERT_EQ(p1.get_fraction_numenator(),3);
    ASSERT_EQ(p1.get_fraction_denominator(), 2);

}

TEST(multiplication, test1) {
    proper_fraction p1(2, 3);
    proper_fraction p2(1, 5);
    p1.fraction_multiplication(p2);

    ASSERT_EQ(p1.get_fraction_numenator(),2);
    ASSERT_EQ(p1.get_fraction_denominator(), 15);

}


TEST(multiplication, test2) {
    proper_fraction p1(2, 3);
    proper_fraction p2(3, 4);
    p1.fraction_multiplication(p2);

    ASSERT_EQ(p1.get_fraction_numenator(),1);
    ASSERT_EQ(p1.get_fraction_denominator(), 2);

}

TEST(multiplication, test3) {
    proper_fraction p1(-2, 3);
    proper_fraction p2(1, 5);
    p1.fraction_multiplication(p2);

    ASSERT_EQ(p1.get_fraction_numenator(),-2);
    ASSERT_EQ(p1.get_fraction_denominator(), 15);

}

TEST(divisionForInt, test1) {
    proper_fraction p1(1, 3);

    p1.fraction_division(5);

    ASSERT_EQ(p1.get_fraction_numenator(),1);
    ASSERT_EQ(p1.get_fraction_denominator(), 15);

}

TEST(divisionForInt, test2) {
    proper_fraction p1(1, 3);

    p1.fraction_division(-7);

    ASSERT_EQ(p1.get_fraction_numenator(),1);
    ASSERT_EQ(p1.get_fraction_denominator(), -21);

}

TEST(divisionForFraction, test1) {
    proper_fraction p1(1, 3);
    proper_fraction p2(2,5);
    p1.fraction_division(p2);

    ASSERT_EQ(p1.get_fraction_numenator(),5);
    ASSERT_EQ(p1.get_fraction_denominator(), 6);
}

TEST(divisionForFraction, test2) {
    proper_fraction p1(4, 5);
    proper_fraction p2(2,5);
    p1.fraction_division(p2);

    ASSERT_EQ(p1.get_fraction_numenator(),2);
    ASSERT_EQ(p1.get_fraction_denominator(), 1);
}

TEST(divisionForFraction, test3) {
    proper_fraction p1(-1, 7);
    proper_fraction p2(2,5);
    p1.fraction_division(p2);

    ASSERT_EQ(p1.get_fraction_numenator(),-5);
    ASSERT_EQ(p1.get_fraction_denominator(), 14);
}

TEST(divisionForFraction, test4) {
    proper_fraction p1(6, 11);
    proper_fraction p2(3,5);
    p1.fraction_division(p2);

    ASSERT_EQ(p1.get_fraction_numenator(),10);
    ASSERT_EQ(p1.get_fraction_denominator(), 11);
}
