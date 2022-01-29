#pragma once
#include "stack.h"
#include "stack.cpp"
#include <string>
using namespace std;

class Calculator {

    Stack<int> vals;
    Stack<char> ops;
    string s;

bool ExpressionIsCorrect(string &s);

    bool IsDigit(char sym) {
        return (sym >= '0' && sym <= '9');

    }

    bool IsOp(char sym) {
        return sym == '+' || sym == '-' || sym == '*' || sym == '/' || sym == '(' || sym == ')';
    }

    int Priority(char operation);

    int Calculate(int val1, int val2, char op);

public:

    Calculator(string s_);
   int Evaluate();

};