#include <iostream>
#include <cmath>
#include <iomanip>
#include <set>

using namespace std;

void solve_quadratic(double a, double b, double c) {
    // N?u a == 0, phuong trình tr? thành phuong trình b?c nh?t
    if (a == 0) {
        if (b != 0) {
            double x = -c / b;
            cout << fixed << setprecision(2) << x << endl;
        } else {
            if (c == 0) {
                cout << "Infinite solutions" << endl;
            } else {
                cout << "No solution" << endl;
            }
        }
        return;
    }

    double delta = b * b - 4 * a * c;

    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        if (x1 > x2) swap(x1, x2); // Ð?m b?o x1 <= x2
        cout << fixed << setprecision(2) << x1 << endl;
        cout << fixed << setprecision(2) << x2 << endl;
    } else if (delta == 0) {
        double x = -b / (2 * a);
        cout << fixed << setprecision(2) << x << endl;
    } else {
        double real_part = -b / (2 * a);
        double imag_part = sqrt(-delta) / (2 * a);
        cout << fixed << setprecision(2) << real_part << " " << -imag_part << endl;
        cout << fixed << setprecision(2) << real_part << " " << imag_part << endl;
    }
}

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    solve_quadratic(a, b, c);

    return 0;
}
