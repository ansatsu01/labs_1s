#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int k, m;
    double x;
    cout << "Input x: ";
    cin >> x;
    cout << "Input k: ";
    cin >> k;

    cout << "Choose the number of digits after comma: ";
    cin >> m;

    double b = cos(x);

    cout << " cos(x) = " << fixed << setprecision(m) << b << endl;

    long double a = 2 * acos(-1);
    cout << fixed << setprecision(m);
    while (x > 35) {
        x -= a;
    }

    double e = (pow(10, -k)) / 2;
    long double p = 1.0;
    double sum = 1.0;
    int n = 1;

    while ((fabs(p)) > e) {
        p *= ((-1) * x * x) / ((2 * n - 1) * 2 * n);
        sum += p;
        n++;
    }

    cout << " Taylor series = " << fixed << setprecision(m) << sum << endl;
    double diff = b - sum;

    cout << " Difference = " << fixed << setprecision (m) << fabs(diff);

    return 0;
}