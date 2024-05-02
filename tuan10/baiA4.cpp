#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 5;
    int *p = &a;
    delete p; // lỗi p trỏ tới biến địa phương, không được giải phóng
    cout << a << endl;
    return 0;
}

