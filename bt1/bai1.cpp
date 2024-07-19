
#include <iostream>
#include <cmath>

using namespace std;

void classify_triangle(int a, int b, int c) {
    // Kiểm tra xem ba cạnh có thỏa mãn bất đẳng thức tam giác hay không
    if (a + b > c && a + c > b && b + c > a) {
        // Tính chu vi tam giác
        int perimeter = a + b + c;
        cout << perimeter << endl;
        
        // Phân loại tam giác
        if (a == b && b == c) {
            cout << "deu" << endl;
        } else if (a == b || a == c || b == c) {
            cout << "can" << endl;
        } else if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2)) {
            cout << "vuong" << endl;
        } else {
            cout << "thuong" << endl;
        }
    } else {
        cout << "Invalid" << endl;
    }
}

int main() {
    int a, b, c;
    // Nhập vào ba số nguyên từ bàn phím
    cin >> a >> b >> c;
    
    // Gọi hàm phân loại tam giác
    classify_triangle(a, b, c);
    
    return 0;
}