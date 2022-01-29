#include "proper_fraction.h"

proper_fraction::proper_fraction(int numerator, int denominator) {
    if (denominator == 0 || (abs(numerator)> abs(denominator))) {
        cout << "the proper fraction is entered incorrectly" << endl;
        exit(1);
    }
        this->numerator = numerator;
        this->denominator = denominator;
        cut_fraction();

}
proper_fraction::proper_fraction(const proper_fraction& copy) {
    this->numerator = copy.numerator;
    this->denominator = copy.denominator;
}

int proper_fraction::get_fraction_numenator() {                    //get-method for num
    return numerator;
}
int proper_fraction::get_fraction_denominator() {             //get-method for denom
    return denominator;
}

void proper_fraction::cut_fraction() {
    int a = min(abs(numerator), abs(denominator));
    for (int i = a; i > 0; i--) {
        if (numerator % i == 0 && denominator % i == 0) {
                numerator = numerator / i;
                denominator = denominator / i;
            }
        }
    }

void proper_fraction::fraction_sum(int num) {           // fraction + number
    numerator = numerator + num * denominator;
    cut_fraction();
}
void proper_fraction::fraction_sum(proper_fraction s) {             //fraction+fraction
    this->numerator = this->numerator * s.denominator;
    s.numerator = s.numerator * this->denominator;
    this->denominator = s.denominator * this->denominator;
    this->numerator = this->numerator + s.numerator;
    cut_fraction();
}

void proper_fraction::fraction_multiplication(proper_fraction mult) {
    this->numerator = this->numerator * mult.numerator;
    this->denominator = this->denominator * mult.denominator;
    cut_fraction();
}
void proper_fraction::fraction_division(int divider) {            //division for integer
    if (divider == 0){
        cout << "denominator must be non-zero" << endl;
        exit(1);
    }
    denominator *= divider;
    cut_fraction();
}
void proper_fraction::fraction_division(proper_fraction divider) {      //division for fraction
    this->numerator = this->numerator * divider.denominator;
    this->denominator = this->denominator * divider.numerator;
    cut_fraction();
}


void proper_fraction::print(){
    if (numerator * denominator < 0){
        cout << "-" << abs(numerator) << "/" << abs(denominator) << endl;
    }
    else if(numerator == 0){
        cout << 0 << endl;
    }
    else{
        cout<< abs(numerator) << "/" << abs(denominator) << endl;
    }
}