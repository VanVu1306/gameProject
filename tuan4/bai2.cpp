#include <bits/stdc++.h>
using namespace std;

const int N = 5;

// Khai báo dạng mảng trong và ngoài hàm main() và không khởi tạo giá trị
char a1[N];

// Khai báo và khởi tạo trong và ngoài hàm main() dạng char a[N] = "abcd"; với N lớn hơn và nhỏ hơn 4, N bằng 4
char a2[N] = "abcd";

// Khai báo và khởi tạo trong và ngoài hàm main() dạng char a[ ] = "abcd"
char a3[] = "abcd";

int main() {
    // In nội dung mảng a1
    for (int i = 0; i < N; i++) {
        cout << a1[i] << " ";
    }
    cout << endl;

    cout << "a1: " << a1 << endl;

    // In nội dung mảng a2
    for (int i = 0; i < N; i++) {
        cout << a2[i] << " ";
    }
    cout << endl;

    cout << "a2: " << a2 << endl;

    // In nội dung mảng a3
    for (int i = 0; i < sizeof(a3); i++) {
        cout << a3[i] << " ";
    }
    cout << endl;

    cout << "a3: " << a3 << endl;

    // Tính kích thước tối đa của xâu kí tự mà mảng có thể lưu được
    int maxLength = sizeof(a1);
    cout << "Kích thước tối đa của xâu kí tự: " << maxLength << endl;

    return 0;
}
