#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    char b[5] = {'A', 'B', 'C', 'D', 'E'};

    // In địa chỉ của 3 phần tử liên tiếp của mảng a
    for (int i = 0; i < 3; i++) {
        cout << &a[i] << endl;
    }

    // In địa chỉ của 3 phần tử liên tiếp của mảng b
    for (int i = 0; i < 3; i++) {
        cout << (void *)&b[i] << endl;
    }

    // Nhận xét:
    // Các địa chỉ của các phần tử liên tiếp trong mảng a có thể không liên tiếp nhau,
    // tùy thuộc vào cách trình biên dịch xử lý việc cấp phát bộ nhớ cho mảng.
    // Các địa chỉ của các phần tử liên tiếp trong mảng b thường liên tiếp nhau,
    // vì mảng b được cấp phát liên tục trong bộ nhớ.

    return 0;
}
