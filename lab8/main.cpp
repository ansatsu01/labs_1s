#include <iostream>
#include "stack.h"
#include "calculate.h"

using namespace std;

int main() {


    Calculator a("3 + 4 + 5");
    Calculator b("3*4 + 5");
    Calculator c("(3+4)*5");
    Calculator d("6+-2");
    Calculator e("1+1/1+1");
    Calculator f ("(1+2))");
    Calculator g ("(((())))12");

    cout << a.Evaluate() << endl;
    cout << b.Evaluate() << endl;
    cout << c.Evaluate() << endl;
    cout << d.Evaluate() << endl;
    cout << e.Evaluate() << endl;
    cout << f.Evaluate() << endl;
    cout << g.Evaluate() << endl;


    return 0;
}
