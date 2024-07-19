#include <iostream>

using namespace std;

void solve_system(double a1, double b1, double c1, double a2, double b2, double c2) {
    double D = a1 * b2 - a2 * b1;
    double Dx = c1 * b2 - c2 * b1;
    double Dy = a1 * c2 - a2 * c1;

    if (D == 0) {
        if (Dx == 0 && Dy == 0) {
            cout << "Vo so nghiem" << endl;
        } else {
            cout << "Vo nghiem" << endl;
        }
    } else {
        double x = Dx / D;
        double y = Dy / D;
        cout << "x = " << x << ", y = " << y << endl;
    }
}

int main() {
    double a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    solve_system(a1, b1, c1, a2, b2, c2);

    return 0;
}
