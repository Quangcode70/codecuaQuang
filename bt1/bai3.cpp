#include <iostream>

using namespace std;

string can_kangaroos_meet(int x1, int v1, int x2, int v2) {
    // Kiểm tra trường hợp đặc biệt khi cả hai con Kangaroo đã đứng cùng một vị trí
    if (x1 == x2) {
        return "YES";
    }
    
    // Nếu vận tốc của hai con Kangaroo bằng nhau nhưng vị trí khởi đầu khác nhau, chúng không thể gặp nhau
    if (v1 == v2) {
        return "NO";
    }
    
    // Kiểm tra xem liệu (x2 - x1) có chia hết cho (v1 - v2) không và (v1 - v2) có cùng dấu với (x2 - x1)
    if ((x2 - x1) % (v1 - v2) == 0 && (x2 - x1) / (v1 - v2) >= 0) {
        return "YES";
    }
    
    return "NO";
}

int main() {
    int x1, v1, x2, v2;
    // Nhập vào các giá trị từ bàn phím
    cin >> x1 >> v1 >> x2 >> v2;

    // Gọi hàm để kiểm tra hai con Kangaroo có thể gặp nhau không
    cout << can_kangaroos_meet(x1, v1, x2, v2) << endl;

    return 0;
}
