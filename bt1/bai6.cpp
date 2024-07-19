#include <iostream>
#include <cmath>

using namespace std;

bool isPerfectSquare(int n) {
    if (n < 0) return false; // Số chính phương không thể là số âm
    int root = static_cast<int>(sqrt(n));
    return root * root == n;
}

int main() {
    int n;
    cin >> n;

    if (isPerfectSquare(n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
