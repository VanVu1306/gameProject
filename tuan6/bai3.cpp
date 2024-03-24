#include <bits/stdc++.h>
using namespace std;

void passByValue(int x) {
    cout << "Address of parameter in passByValue: " << &x << endl;
    x = 10;
}

void passByReference(int& x) {
    cout << "Address of parameter in passByReference: " << &x << endl;
    x = 20;
}

int main() {
    int num = 5;
    cout << "main: " << &num << endl;

    passByValue(num);
    cout << "passByValue: " << num << endl;

    passByReference(num);
    cout << "passByReference: " << num << endl;

    // Nhận xét:
    // - Khi truyền tham số theo cơ chế tham trị (pass-by-value), một bản sao của giá trị của biến được tạo ra và sử dụng trong hàm.
    //   Điều này được chứng minh bởi các địa chỉ khác nhau giữa biến gốc và tham số trong hàm passByValue.
    // - Khi truyền tham số theo cơ chế tham chiếu (pass-by-reference), biến tham chiếu trực tiếp đến địa chỉ của biến gốc.
    //   Điều này được chứng minh bởi cùng một địa chỉ giữa biến gốc và tham số trong hàm passByReference.

    return 0;
}
