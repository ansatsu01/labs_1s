#pragma once
#include<iostream>
using namespace std;

class proper_fraction {
public:
    proper_fraction(int num, int denom);
    proper_fraction(const proper_fraction& copy);
    int get_fraction_numenator();
    int get_fraction_denominator();
    void print();
    void cut_fraction();
    void fraction_sum(int num);
    void fraction_sum(proper_fraction s);
    void fraction_multiplication(proper_fraction mult);
    void fraction_division(int divider);
    void fraction_division(proper_fraction divider);
private:
    int numerator;
    int denominator;
};






















































 /*#pragma once
#include<iostream>
using namespace std;

class proper_fraction {

    proper_fraction(int numerator, int denominator){
        if (denominator == 0 || numerator >= denominator) {
             cout << "error" << endl;
             exit(1);
        }
        this->denominator = denominator;
        this->numerator = numerator;
    }

    int numerator;
    int denominator;

};

*/