#include <bits/stdc++.h>
using namespace std;

const int N = 4;

// Khai báo mảng trong và ngoài hàm main() và không khởi tạo giá trị cho mảng
int array1[N];

// Khai báo và khởi tạo trong và ngoài hàm main() dạng int a[N] = {1, 2, 3, 4} với N lớn hơn và nhỏ hơn 4
int array2[N] = {1, 2, 3, 4};

// Khai báo và khởi tạo trong và ngoài hàm main() dạng int a[ ] = {1, 2, 3, 4}
int array3[] = {1, 2, 3, 4};

int main() {
    // In nội dung mảng array1
    for (int i = 0; i < N; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;

    // In nội dung mảng array2
    for (int i = 0; i < N; i++) {
        cout << array2[i] << " ";
    }
    cout << endl;

    // In nội dung mảng array3
    for (int i = 0; i < 4; i++) {
        cout << array3[i] << " ";
    }
    cout << endl;

    return 0;
}
