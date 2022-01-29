#include "calculate.h"

Calculator::Calculator(string s_){
this->s = s_;
}

bool Calculator::ExpressionIsCorrect(string &s) {

    int count_of_open_br = 0;
    int count_of_closing_br = 0;

    for (int i = 0; i < s.length(); ++i){
        if(s[i] == '(') {count_of_open_br++;}
        if(s[i] == ')') {count_of_closing_br++;}
    }

    if (count_of_open_br != count_of_closing_br){
        return false;
    }
if (s[s.length() - 1] != ')' && IsOp(s[s.length() - 1])) {
    return false;
}
    return true;
}

int Calculator::Priority(char operation) {

    if (operation == '+' || operation == '-') { return 1; }
    if (operation == '*' || operation == '/') { return 2; }
    if (operation == '(' || operation == ')') { return 3; }
    return -1;
}


int Calculator::Calculate(int val1, int val2, char op) {

    if (op == '+') {
        return val1 + val2;
    }
    if (op == '-') {
        return val1 - val2;
    }
    if (op == '*') {
        return val1 * val2;
    }
    if (op == '/') {
        return val1 / val2;
    }
}

int Calculator::Evaluate() {

    if(!ExpressionIsCorrect(s)){
        throw std::out_of_range ("Invalid expression");
    }



    int val = 0;
    int pos = 0;

    while (pos < s.length()) {

        char spot = s[pos];
        if (IsDigit(spot)) {

            val = (val * 10) + (int) (spot - '0');
        } else if (IsOp(spot)) {

            if (spot == '(') {
                ops.push(spot);
                val = 0;
            } else if (vals.IsEmpty()) {

                vals.push(val);
                ops.push(spot);
                val = 0;
            } else if (spot == ')') {

                vals.push(val);
                while (ops.peek() != '(') {

                    spot = ops.pop();
                    val = vals.pop();
                    int prev = vals.pop();
                    val = Calculate(prev, val, spot);
                    vals.push(val);
                }
                ops.pop();
                vals.pop();
            } else {

                char prev = ops.peek();
                if (Priority(spot) > Priority(prev)) {

                    vals.push(val);
                    ops.push(spot);
                    val = 0;
                } else {

                    int prevval = vals.pop();
                    char prev_op = ops.pop();
                    prevval = Calculate(prevval, val, prev_op);
                    vals.push(prevval);
                    ops.push(spot);
                    val = 0;

                }
            }
        }
        pos++;
    }
    while (!ops.IsEmpty()) {
        int prev = vals.pop();
        char spot = ops.pop();
        val = Calculate(prev, val, spot);
    }
    return val;
}
